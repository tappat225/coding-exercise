/**
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 
 * 请你找出所有和为 0 且不重复的三元组。
 * 注意：答案中不可以包含重复的三元组。
 * 
 * Link: https://leetcode-cn.com/problems/3sum/
 */

#include "../../Tools_function/head_cpp.h"

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> result;
    vector<int> neg_arr;
    vector<int> pos_arr;
    int n;

    n = nums.size();
    if (n < 3) {
        return {};
    }

    sort(nums.begin(), nums.end());
    for (auto num:nums) {

    }
}

int main()
{

}
