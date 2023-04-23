#include "../Tools_function/head_c.h"

/**
 * 二维数组的形参格式：
 * int arr[3][5]或int (*arr)[5]或int *arr(用一维数组形式访问二维数组)
 */
int **sort_arr(int arr[][2], int pair_num)
{
    int **ans_arr;
    int i;

    ans_arr = (int **)malloc(sizeof(int*) * pair_num);

    for(i = 0; i < pair_num; i++) {
        ans_arr[i] = (int *)malloc(sizeof(int) * 2);
        ans_arr[i][0] = arr[i][0];
        ans_arr[i][1] = arr[i][1];;
    }

    return ans_arr;
}

/* 二维指针必须写int **arr，不能跟二维数组搞混 */
void print_double_arr(int **arr, int size)
{
    int i;
    printf("[");
    for (i = 0; i < size - 1; i++) {
        printf("[%d, %d],", arr[i][0], arr[i][1]);
        free(arr[i]);
    }

    printf("[%d, %d]", arr[i][0], arr[i][1]);
    printf("]\n");
    free(arr[size - 1]);
}

int main()
{
    int arr[3][2] = {{10, 30}, {20, 60}, {80, 100}};
    int **p;

    p = sort_arr(arr, 3);
    print_double_arr(p, 3);
    if (p != NULL) {
        free(p);
    }

    return 0;
}
