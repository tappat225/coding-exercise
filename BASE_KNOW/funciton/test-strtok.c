#include <stdio.h>
#include <string.h>

int main()
{
    char str[10] = "eth0.1";
    char *sub_str;
    char* pToken = NULL;
    char* pSave = NULL;

    const char t[2] = ".";
    sub_str = strtok(str, t);
    pToken = __strtok_r(str, t, &pSave);
    printf("sub_str = %s\n", sub_str);
    printf("pToken = %s, pSave = %s\n", pToken, pSave);
    return 0;
}
