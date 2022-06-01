#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ss {
    char a;
    short b;
    int c;
    char d;
}ss_t;

typedef struct s2 {
    char a;
    short d;
}s2_t;

int main(void) {
    // ss_t myss;
    printf("sizeof(ss) = %d\n", sizeof(ss_t));
    printf("sizeof(s2) = %d\n", sizeof(s2_t));
    printf("sizeof(char) = %d\n", sizeof(char));
    printf("sizeof(short) = %d\n", sizeof(short));
    printf("sizeof(int) = %d\n", sizeof(int));
    return 0;
}

