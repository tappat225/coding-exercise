#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

const int maxn = 1024;

typedef struct mem_size {
    int KernelPageSize;
    int MMUPageSize;
    int Private_Clean;
    int Private_Dirty;
    int Pss;
    int Referenced;
    int Rss;
    int Shared_Clean;
    int Shared_Dirty;
    int Size;
    int Swap;
}mem_size_t;

typedef struct fd_type {
    int CommonFile;
    int Device;
    int socket;
}fd_type_t;

typedef struct process{
    char     uid[20];
    int      pid;
    char     command[50];
    mem_size_t MemoryUsage;
    fd_type_t  fd_num;
}process_t;

inline static void get_smaps_filepath(int pid, char *filepath) {
    sprintf(filepath, "/proc/%d/smaps", pid);
}

inline static void get_status_filepath(int pid, char *filepath) {
    sprintf(filepath, "/proc/%d/status", pid);
}

inline static void get_FD_DirPath(int pid, char *dirpath) {
    sprintf(dirpath, "/proc/%d/fd", pid);
}

static bool isFileEmpty(char *filepath) {
    bool flag = true;
    FILE *fp = fopen(filepath, "r");
    char ch = fgetc(fp);
    fclose(fp);
    if (ch != EOF) {
        flag = false;
    }
    return flag;
}

static int isFileExist(FILE *fp, char *filepath) {
    if (!fp) {
        perror(filepath);
        return 1;
    } else {
        return 0;
    }
}

static int isProcessValid(int pid) {
    char smaps_filepath[100];
    char FD_dirpath[100];
    get_smaps_filepath(pid, smaps_filepath);
    get_FD_DirPath(pid, FD_dirpath);

    if(access(smaps_filepath, F_OK) == -1 || opendir(FD_dirpath) == NULL || isFileEmpty(smaps_filepath)) {
        return -1;
    }

    return 0;
}

/* 由PID获取所属用户名 */
static void get_Uid(int pid, char *uid_s) {
    const int size = 10;
    char command[100];
    sprintf(command, "ps -ef | awk '$2 ~ /^%d$/ {print $1}'", pid);
    FILE *fp = popen(command, "r");
    fgets(uid_s, size, fp);
    pclose(fp);
    int len = strlen(uid_s);
    uid_s[len-1] = '\0'; 
}

/* 由PID获取对应命令行 */
static void get_command(int pid, char *comline_s) {
    const int size = 100;
    char command[100];
    FILE *fp;

    sprintf(command, "ps -ef | awk '$2 ~ /^%d$/ {print $8}'", pid);
    fp = popen(command, "r");
    fgets(comline_s, size, fp);
    pclose(fp);
}

/* 从/proc/PID/status中读取命令行 */
static void get_command2(int pid, char *comline_s) {
    char filepath[100];
    char line[100];
    char substr[20];
    int i = 0;
    int j = 0;

    get_status_filepath(pid, filepath);
    FILE *fp = fopen(filepath, "r");

    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "%31[^:]", substr) == 1) {
            if (strcmp(substr, "Name") == 0) {
                for (i = 6; i < strlen(line); i++) {
                    if(line[i] == ' ') {
                        continue;
                    } else {
                        comline_s[j] = line[i];
                        j++;
                    }
                }
                break;
            }
        }
    }

}

/* 获取某一路径下的文件数目 */
static int get_filenum(char *FilePath) {
    char command[100];
    char buff[10];
    int retval;

    sprintf(command, "ls -l %s | wc -l", FilePath);
    FILE *fp = popen(command, "r");
    fgets(buff, sizeof buff, fp);
    pclose(fp);
    retval = atoi(buff) - 1;

    return retval;
}

/* 获取句柄数量 */
static int get_fd_num(int pid) {
    char filepath[100];
    char buff[50];
    int retval;
    FILE *fp;

    memset(buff, 0, sizeof buff);
    sprintf(filepath, "ls -l /proc/%d/fd/ | wc -l", pid);
    fp = popen(filepath, "r");
    if(isFileExist(fp, filepath) == 1) {
        return -1;
    }

    fgets(buff, 10, fp);
    pclose(fp);
    retval = atoi(buff)-1;

    return retval;
}

/* 获取RSS占用 */
static int get_rss_size(int pid) {
    char filepath[100];
    char line[maxn];
    char substr[32];
    char data[10];
    int i;
    int j;
    FILE *fp;
    int data_sum;

    get_smaps_filepath(pid, filepath);
    fp = fopen(filepath, "r");
    data_sum = 0;
    /* 读入smaps并提取计算出RSS总大小 */
    while (fgets(line, sizeof(line), fp)) {
        memset(data, 0, sizeof(data));
        j = 0;
        if (sscanf(line, "%31[^:]", substr) == 1) {
            if (strcmp(substr, "Rss") == 0) {
                for (i = 0; i < strlen(line); i++) {
                    if('0'<=line[i] && line[i]<='9') {
                        data[j] = line[i];
                        j++;
                    }
                }

                data_sum += atoi(data);
            }
        }
        
    }

    return data_sum;
}

/* 获取RSS占用 */
static int get_Size2 (int pid) {
    char command[100];
    char buff[20];
    int retval;
    FILE *fp;

    sprintf(command, "awk '/Rss:/{ sum += $2 } END { print sum }' /proc/%d/smaps", pid);
    fp = popen(command, "r");
    fgets(buff, sizeof buff, fp);
    retval = atoi(buff);

    return retval;
}

/* 获取/proc/下所有进程项的数目 */
static int get_all_process_num () {
    char buff[10];
    int retval;
    FILE *fp;

    fp= popen("ls -l /proc/ | awk '$9 ~ /[0-9]/ ' | wc -l", "r");
    fgets(buff, sizeof buff, fp);
    pclose(fp);
    retval = atoi(buff);

    return retval;
}

/* 获得指定进程名相关进程的数目 */
static int get_specific_process_num (char *processName) {
    char command[100];
    char buff[10];
    int retval;
    FILE *fp;

    sprintf(command, "ps -ef | awk '$8 ~ /'%s'/ '| wc -l", processName);
    fp = popen(command, "r");
    fgets(buff, 10, fp);
    retval = atoi(buff);

    return retval;
}

static int compare_function(const void *a, const void *b) {
    const int aa = (*(process_t *)a).MemoryUsage.Rss;
    const int bb = (*(process_t *)b).MemoryUsage.Rss;
    return (aa < bb) - (aa > bb);
}

/* fp得到PID列表，逐次写入进程信息 */
static void write_process_info (process_t *this_process, FILE *fp, int *process_num) {
    char *buff;
    int pid_buff;
    int i;

    buff = (char*)malloc(10 * sizeof(char));
    memset(buff, 0, 10);
    i = 0;
    /* 此处buff得到的是PID */
    while (fgets(buff ,sizeof buff, fp) != NULL) {
        pid_buff = atoi(buff);
        if(isProcessValid(pid_buff) < 0) {
            continue;
        }
        
        this_process[i].pid = pid_buff;
        get_Uid(pid_buff, this_process[i].uid);
        get_command2(pid_buff, this_process[i].command);
        this_process[i].fd_num.CommonFile = get_fd_num(pid_buff);
        this_process[i].MemoryUsage.Rss = get_rss_size(pid_buff);
        i++;
        memset(buff, 0, 10);
    }

    free(buff);
    *process_num = i;
}

/* 指定进程名并写入信息 */
static void AnalysisSpecificProcess (char *processName, process_t *this_process, int *process_num) {
    char process_pid_get_command[50];

    sprintf(process_pid_get_command, "ps -ef | awk '$8 ~ /'%s'/ {print $2;}'", processName);
    FILE *fp = popen(process_pid_get_command, "r");
    write_process_info(this_process, fp, process_num);
    pclose(fp);
}

/* 写入进程(all)信息，进程数目用传地址方式传参 */
static void AnalysisAllProcess (process_t *this_process, int *process_num) {
    FILE *fp;

    fp= popen("ls -l /proc/ | awk '$9 ~ /[0-9]/ {print $9;}'", "r");  /* 读入全部进程PID */
    write_process_info(this_process, fp, process_num);
    pclose(fp);
}

static void print_info (process_t *this_process, int process_num) {
    int j;
    char *row[] = {"PID", "UID", "FD", "RES", "COM"};

    printf("%-8s | %-8s | %-4s | %-8s | %s\n", row[0], row[1], row[2], row[3], row[4]);
    for (j = 0; j < process_num; j++) {
        printf("%-8d | %-8s | %-4d | %-8d | %s\n", this_process[j].pid, this_process[j].uid, 
               this_process[j].fd_num.CommonFile, this_process[j].MemoryUsage.Rss, 
               this_process[j].command);
    }
}

int main (int argc, char *argv[]) {
    process_t *this_process;
    int opt;
    int ProcessCount;
    char process_name[20];
    char filepath[100];
    
    opt = -1;
    ProcessCount = 0;
    /* 支持选项指定特定进程 */
    if (argc > 1) {
        while ((opt = getopt(argc, argv, "p:")) != -1) {
            switch (opt) {
            case 'p':
                if ((ProcessCount = get_specific_process_num(optarg)) < 1) {
                    printf("Process not found!\n");
                    goto done;
                }

                if ((this_process = (process_t*)malloc(ProcessCount * sizeof(process_t))) == NULL) {
                    printf("oh bad!\n");
                    goto done;
                }
                memset(this_process, 0, sizeof(process_t));
                AnalysisSpecificProcess(optarg, this_process, &ProcessCount);
                break;
            
            default:
                printf("Not a valid option!\n");
                goto done;
                break;
            }
        }
    } else {
        /* 分析所有进程 */
        ProcessCount = get_all_process_num();
        printf("count = %d\n", ProcessCount);
        if ((this_process = (process_t*)malloc(ProcessCount * sizeof(process_t))) == NULL) {
            printf("oh bad!\n");
            goto done;
        }
        
        memset(this_process, 0, sizeof(process_t));
        AnalysisAllProcess(this_process, &ProcessCount);
        printf("count = %d\n", ProcessCount);
        qsort(this_process, ProcessCount, sizeof(process_t), compare_function);
    }
    
    print_info(this_process, ProcessCount);
    free(this_process);

done:
    return 0;
}
