#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int g_i;

void thread(void)
{
    int i;

    for(i = 0; i < 4; i++) {
        printf("This is a pthread. chaneg: %d -> %d\n", g_i, ++g_i);
        sleep(1);
    }

    printf("Thread done.\n");
}

int main(void)
{
    pthread_t id;
    int i, ret;

    g_i = 0;
    /**
     * @arg 1: 线程句柄，创建成功后返回给调用者
     * @arg 2: 线程属性，可选
     * @arg 3: 入口函数
     * @arg 4：入口函数的参数
     */
    ret = pthread_create(&id, NULL, (void*)thread, NULL);
    if(ret != 0) {
        printf("Create pthread error!\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < 3; i++) {
        printf("This is the main process. change %d -> %d\n", g_i, ++g_i);
        sleep(1);
    }

    pthread_join(id, NULL); /* 等待子线程处理完 */
    printf("Main process done.\n");
    return 0;
}
