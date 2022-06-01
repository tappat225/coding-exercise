/**
 * 题目:
 * 输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
 * 要求时间复杂度为O(n)。
 * 
 * example:
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * 
 * Tags: 动态规划，贪心算法
 * 
 * State: Resolved.
 * Link: https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
 */

#include "../../Tools_function/head_cpp.h"

using namespace std;

#define TANXIN

#ifdef TANXIN
/**
 * 贪心算法思想:
 * 只关注当前求和是否大于0，若求和比0小，则以当前元素为起始重新求和，实时更新最大求和数
 */
int maxSubArray(vector<int>& nums)
{
    int maxsum;
    int sum;

    maxsum = nums[0];
    sum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        sum = (sum > 0) ? (sum + nums[i]) : nums[i];
        maxsum = max(sum, maxsum);
    }

    return maxsum;
}

#else
/**
 * 动态规划思想:
 * 始终假设当前所选元素为数组最后一个，若加上当前元素的和比元素自身还小，则以当前元素为起始，重新求序列和
 */
int maxSubArray(vector<int>& nums)
{
    int sum;
    int maxsum;

    sum = nums[0];
    maxsum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        sum += nums[i];
        if (sum < nums[i]) {
            sum = nums[i];
        }

        maxsum = max(sum, maxsum);
    }

    return maxsum;
}

#endif

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int max;

    max = maxSubArray(nums);
    cout << "max = " << max << endl;
    return 0;
}