/**
 * 
 * State: resolved.
 * Link: https://leetcode-cn.com/problems/maximum-difference-between-increasing-elements/
 */

#include "../../Tools_function/head_cpp.h"

using namespace std;

#ifdef FA1

#else
/* 时间效率太低 O(n^2) */
int maximumDifference(vector<int>& nums)
{
    int i,j;
    int diff = -1;
    int this_diff;

    for (i = 0; i < nums.size(); i++) {
        for (j = i + 1; j < nums.size(); j++) {
            if (nums[i] < nums[j]) {
                this_diff = nums[j] - nums[i];
                diff = (this_diff > diff) ? this_diff : diff;
            }
        }
    }

    return diff;
}
#endif

int main()
{
    vector<int> nums = {1, 5, 2, 10};

    cout << maximumDifference(nums) << endl;
    return 0;
}

