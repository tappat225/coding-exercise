/**
 * Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).
 * The algorithm for myAtoi(string s) is as follows:
 * 
 * Read in and ignore any leading whitespace.
 * Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either.
 * This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
 * Read in next the characters until the next non-digit charcter or the end of the input is reached. The rest of the string is ignored.
 * Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0.
 * Change the sign as necessary (from step 2).
 * 
 * If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], 
 * then clamp the integer so that it remains in the range. Specifically,
 * integers less than -2^31 should be clamped to -2^31,
 * and integers greater than 2^31 - 1 should be clamped to 2^31 - 1.
 * 
 * Return the integer as the final result.

Note:
 * Only the space character ' ' is considered a whitespace character.
 * Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
 *
 * Link：https://leetcode-cn.com/problems/string-to-integer-atoi
 * 
 * State: Unresolved.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TEST

#ifdef TEST
bool isNum(char c)
{
    return (c >= '0' && c <= '9');
}

int myAtoi(char *s)
{
    int i;
    long num;
    bool minus_flag;
    int flag_front;
    int num_count;
    bool num_check;

    minus_flag = false;
    num_check = false;
    num = 0;
    num_count = 0;
    i = 0;
    flag_front = 0;
    while (s[i] == ' ') {
        i++;
    }

    while (s[i] == '+' || s[i] == '-') {
        flag_front ++;
        if (s[i] == '-') {
            minus_flag = true;
        }

        if (flag_front > 1) {
            return 0;
        }

        i++;
    }

    while (s[i] != '\0') {
        if (s[i] == '0' && !num_check) {
            i++;
            continue;
        }

        if (num_count > 10) {
            break;
        }

        if (isNum(s[i]) && num_check) {
            num *= 10;
            num += s[i] - '0';
            i++;
            num_count ++;
        } else if (s[i] == '.' || !isNum(s[i])) {
            break;
        }
    }
    

    if (minus_flag) {
        num = 0 - num;
    }

    if (num < -2147483648) {
        num = -2147483648;
    } else if (num > 2147483647) {
        num = 2147483647;
    }

    return num;
}
#else
int myAtoi(char *s)
{
    char num_s[64];
    char flag[10];
    int i;
    long num;

    num = 0;
    sscanf(s, "%[0-9]", num_s);
    printf("flag = %s\n", flag);
    printf("num_s = %s\n", num_s);
    i = strlen(flag);
    if (i > 1) {
        return 0;
    }

    i = 0;
    while (num_s[i] != '\0') {
        num *= 10;
        num += num_s[i] - '0';
        i++;
    }

    if (num < -2147483648) {
        num = -2147483648;
    } else if (num > 2147483647) {
        num = 2147483647;
    }

    return num;
}

#endif

int main()
{
    char my_string[128];
    long num;
    printf("Input a num string: ");
    scanf("%[^\n]", my_string);
    num = myAtoi(my_string);
    printf("num = %ld\n", num);
    return 0;
}
