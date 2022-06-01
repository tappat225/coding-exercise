#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "test.h"

// static void free_point(char **p) {
//     if (*p) {
//         free(*p);
//         *p = NULL;
//     }
// }

typedef enum {
    ABC = 1,
} abc;

typedef enum __attribute__((packed)) {
    BCD = 1,
} bcd;

int main(){

    printf("sizeof ABC = %d\n", sizeof(abc));
    printf("sizeof BCD = %d\n", sizeof(bcd));
    return 0;
}
