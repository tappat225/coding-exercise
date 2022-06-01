#include<stdio.h>
#include<stdlib.h>

int main() {
    int i;
    /* 使用malloc完成char p[5]的效果 */
    char* p=(char*)malloc(sizeof(char)*5);
    printf("input 5 characters: ");
    scanf("%s",p);
    printf("the string is: ");
    for(i=0;i<5;i++){
        printf("%c",*(p+i));
    }
    free(p);
    return 0;

}