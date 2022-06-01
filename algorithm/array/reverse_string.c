/**
 * @file reverse_string.c
 * @author your name (you@domain.com)
 * @brief 反转字符串
 * @version 0.1
 * @date 2022-05-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../Playground/test_header.h"

char *reverse_str(char *str)
{
    char temp;
    int len;
    int left;
    int right;

    if (str == NULL) {
        return NULL;
    }

    len = strlen(str);
    left = 0;
    right = len - 1;
    while (left < right) {
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }

    return str;
}

int main()
{
    char test_str[] = "hello";
    char *str;

    str = reverse_str(test_str);
    printf("%s\n", str);
    return 0;
}
