/* 
 * Copyright(C) 2005 inc. All rights reserved.
 */
/*
 * num_check.c
 * Original Author:  , 2021-5-31
 *
 * Check if string can be converted into a valid number.
 *
 */

#include<stdio.h>
#include<stdbool.h>

const int maxn = 20;

static bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}

static int is_number(char* s)
{
    int i;
    bool contains_digits;
    bool contains_dec_point;

    i = 0;
    contains_digits = false;
    contains_dec_point = false;
    /* skip the spaces */
    while (s[i] && s[i] == ' ') {
        i++;
    }

    if (s[i] == 0) {
        return 0;
    }

    if (s[i] == '+' || s[i] == '-') {
        i++;
    }

    if (!is_digit(s[i]) && s[i] != '.') {
        return 0;
    }

   
    while (is_digit(s[i]) || s[i]=='.') {
        if (is_digit(s[i])) {
            contains_digits = true;
        }

        if (s[i] == '.') {
            if (contains_dec_point) {
                return 0;
            }
            contains_dec_point = true;
        }

        i++;
    }

    if (!contains_digits) {
        return 0;
    }

    if (s[i] == 'e') {
        i++;
        if (s[i] == '-' || s[i] == '+') {
            i++;
        }
        /* digits after the exp.sign are necessarily */
        if (!is_digit(s[i])) {
            return 0;
        }

        while (is_digit(s[i])) {
            i++;
        }
    }
    /* ending spaces */
    while (s[i] ==' ') {
        i++;
    }
    /* the end of the string */
    if (s[i] != '\n') {
        return 0;
    }

    return 1;
}

int main(int argc, char *argv[])
{
    char str[maxn];

    fgets(str, maxn, stdin);
    printf("%d\n", is_number(str));
    return 0;
}
