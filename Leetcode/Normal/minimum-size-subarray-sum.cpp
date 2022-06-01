/**
 * Description:
 * Given an array of positive integers nums and a positive integer target,
 * return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr]
 * of which the sum is greater than or equal to target.
 * If there is no such subarray, return 0 instead.
 * 
 * Tags: 滑动窗口
 * 
 * State: Resolved.
 * 
 * Link: https://leetcode-cn.com/problems/minimum-size-subarray-sum/
 */

#include "../../Tools_function/head_cpp.h"

using namespace std;

int minSubArrayLen(int target, vector<int>& nums)
{
    int i, j;
    int len;
    int sum;
    bool flag;

    i = 0;
    j = 0;
    len = nums.size();
    flag = false;
    while (i <= j && j < nums.size()) {
        sum = 0;
        for (int p = i; p <= j; p++) {
            sum += nums[p];
        }

        if (sum < target) {
            j++;
        } else {
            flag = true;
            len = ((j - i + 1) < len) ? (j - i + 1) : len;
            i++;
        }
    }

    return (flag == true) ? len : 0;
}

int main()
{
    char x;
    vector<int>nums {1, 2, 3, 4, 5};
    int target;

    // cout << "Input an array: ";
    // while (cin >> x) {
    //     if (x == ' ') {
    //         continue;
    //     }

    //     if (getchar() == '\n' || isdigit(x) == 0) {
    //         break;
    //     }

    //     nums.push_back(x - '0');
    // }

    cout << "Input target num : ";
    cin >> target;
    cout << "min_len = " << minSubArrayLen(target, nums) << endl;

    return 0;
}