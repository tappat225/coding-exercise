/* 获取句柄数量 */
static int get_FD_num(char *pid_s) {
    char filepath[100];
    char buff[50];
    int retval;
    memset(buff, 0, sizeof buff);
    sprintf(filepath, "ls -l /proc/%s/fd/ | wc -l", pid_s);
    FILE *fp = popen(filepath, "r");
    fgets(buff, 50, fp);
    pclose(fp);
    printf("buff= %s\n", buff);
    retval = atoi(buff)-1;
    return retval;
}