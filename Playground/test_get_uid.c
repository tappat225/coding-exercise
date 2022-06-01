#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main(int argc, char *argv[])
{
    uid_t ruid, euid, suid;

    if(getresuid(&ruid, &euid, &suid) == -1)
    {
        fprintf(stderr, "getresuid error:%s.\n", strerror(errno));
        return 1;
    }
    printf("PID=%d, real uid=%ld, effective uid=%ld, save set-user-ID=%ld\n",
          getpid(), (long)ruid, (long)euid, (long)suid);

    return 0;
}