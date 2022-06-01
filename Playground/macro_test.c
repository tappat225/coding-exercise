#include <stdio.h>

int test()
{
    #define _N(M,m) do{\
    printf(#M "M= %c\n", M); \
    printf(#m "m = %d\n",m);\
    }while(0)

    _N('a', 1);
    _N('b', 2);

#undef _N
    return 0;
}
/* ##可以粘贴在语句旁边或中间，#相当于声明宏参数 */
#define _N(M,m) \
static void print_val_##M()\
{\
printf(#m"is in %d, val = %d\n", __LINE__, m);\
printf("try to show M = "#M" as well\n");  \
}\

_N(k, 11)
_N(j, 22)

int main()
{
    test();
    print_val_j();
    print_val_k();
    return 0;
}