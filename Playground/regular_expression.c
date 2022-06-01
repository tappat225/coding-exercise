#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int get_num_from_string(char *str)
{
    int i, k, num, len;
    char num_s[5];

    num = 0;
    k = 0;
    len = strlen(str);
    for (i = 0;i < len; i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            num_s[k] = str[i];
            k++;
        }
    }
    num = atoi(num_s);
    return num;
}

int main()
{
    char a[10] = "hello12";
    // char num_s[2] = {0};
    int num = 0;
    // sscanf(a, "/[^0-9]/", num_s);
    num = get_num_from_string(a);
    printf("num = %d\n", num);
    return 0;
}