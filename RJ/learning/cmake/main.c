#include <stdio.h>
#include "fun.h"

int main() {
    int a, b, sum;

    a = 4;
    b = 3;
    sum = fun_sum(a, b);
    printf("sum = %d\n", sum);
    return 0;
}
