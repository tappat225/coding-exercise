/**
 * 统计一个数字在排序数组中出现的次数。
 * 
 * Link: https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
 * 
 * State: Passed.
*/

#include <stdio.h>
#include <stdlib.h>

int search(int *nums, int numsSize, int target)
{
    int i;
    int count;

    count = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            count ++;
        }
    }

    return count;
}

int main()
{
    int i;
    int *num;
    int array_size;
    int count_times;
    int target;
    printf("Input array size: ");
    scanf("%d", &array_size);
    num = (int *)malloc(array_size * sizeof(int));
    printf("Input a num array: ");
    for (i = 0; i < array_size; i++) {
        scanf("%d", &num[i]);
    }

    printf("Input the target num: ");
    scanf("%d", &target);
    count_times = search(num, array_size, target);
    printf("Target found %d times in num array.\n", count_times);
    free(num);
    num = NULL;
    return 0;
}