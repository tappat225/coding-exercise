#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct smaps_sizes {
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
};

static char* get_filepath(char *pid, char *filepath) {
    char path_prefix[7] = "/proc/";
    char path_postfix[8] = "/smaps";
    int len = strlen(path_prefix);
    strncpy(filepath, path_prefix, strlen(path_prefix));
    strncpy(filepath+len, pid, strlen(pid));
    len += strlen(pid); 
    strncpy(filepath+len, path_postfix, strlen(path_postfix));
    len +=strlen(path_postfix);
    *(filepath+len) = '\0';
    return filepath;
}

/* 由PID构建对应Smaps路径 */
static void get_SmapsFilePath(char *pid, char *filepath) {
    char path_prefix[7] = "/proc/";
    char path_postfix[8] = "/smaps";
    int len = strlen(path_prefix);
    strncpy(filepath, path_prefix, strlen(path_prefix));
    strncpy(filepath+len, pid, strlen(pid));
    len += strlen(pid); 
    strncpy(filepath+len, path_postfix, strlen(path_postfix));
    len += strlen(path_postfix);
    *(filepath+len) = '\0';
}

static int str2int(char *str) {
    int len = strlen(str);
    if(len < 1) {
        return 0;
    }
    int k;
    int i=0;
    int retval=0;
    for(k = len-1; k >= 0; k--) {
        retval += (str[k] - '0') * pow(10,i);
        i++;
    }
    return retval;
}

int main(){
    char filepath[50];
    char PID[10];
    printf("PID: ");
    scanf("%s",PID);
    get_filepath(PID, filepath);

    printf("filepath= %s\n", filepath);
    struct smaps_sizes sizes;
    memset(&sizes, 0, sizeof(sizes));

    // FILE *fp = fopen("/proc/1470/smaps", "r");
    FILE *fp = fopen(filepath, "r");
    // FILE *ffp = fopen("./test.txt", "w+");

    if (!fp) {
        perror(filepath);
        return 1;
    }
    char line[1024];
    int data_sum;
    // fgets(line, sizeof(line), fp);
    // puts(line);

    /* char ch;
    while((ch=fgetc(fp))!=EOF) {
        fputc(ch,ffp);
    }

    
    fclose(ffp); */

    while (fgets(line, sizeof(line), fp)) {
        char substr[32];
        char data[10];
        
        memset(data, 0, sizeof(data));
        // int n;
        int i;
        int j=0;
        if (sscanf(line, "%31[^:]", substr) == 1) {
            if (strcmp(substr, "Rss") == 0) {
                for (i = 0; i < strlen(line); i++) {
                    if('0'<=line[i] && line[i]<='9') {
                        data[j] = line[i];
                        j++;
                    }
                }

                // fprintf(stdout, "Rss %s\n", data);
                data_sum += str2int(data);
            }
        }
        
        
        /* if (sscanf(line, "%31[^:]%n", substr, &n) == 1) {
            if      (strcmp(substr, "KernelPageSize") == 0) { sizes.KernelPageSize += n; }
            else if (strcmp(substr, "MMUPageSize") == 0)    { sizes.MMUPageSize += n; }
            else if (strcmp(substr, "Private_Clean") == 0)  { sizes.Private_Clean += n; }
            else if (strcmp(substr, "Private_Dirty") == 0)  { sizes.Private_Dirty += n; }
            else if (strcmp(substr, "Pss") == 0)            { sizes.Pss += n; }
            else if (strcmp(substr, "Referenced") == 0)     { sizes.Referenced += n; }
            else if (strcmp(substr, "Rss") == 0)            { sizes.Rss += n; }
            else if (strcmp(substr, "Shared_Clean") == 0)   { sizes.Shared_Clean += n; }
            else if (strcmp(substr, "Shared_Dirty") == 0)   { sizes.Shared_Dirty += n; }
            else if (strcmp(substr, "Size") == 0)           { sizes.Size += n; }
            else if (strcmp(substr, "Swap") == 0)           { sizes.Swap += n; }
        } */
    }

    fprintf(stdout, "Rss_total= %d KB\n", data_sum);

    // printf("KernelPageSize %d\n", sizes.KernelPageSize);
    // printf("MMUPageSize %d\n", sizes.MMUPageSize);
    // printf("Private_Clean %d\n", sizes.Private_Clean);
    // printf("Private_Dirty %d\n", sizes.Private_Dirty);
    // printf("Pss %d\n", sizes.Pss);
    // printf("Referenced %d\n", sizes.Referenced);
    // printf("Rss %d\n", sizes.Rss);
    // printf("Shared_Clean %d\n", sizes.Shared_Clean);
    // printf("Shared_Dirty %d\n", sizes.Shared_Dirty);
    // printf("Size %d\n", sizes.Size);
    // printf("Swap %d\n", sizes.Swap);

    fclose(fp);
    
    return 0;
}