/**
 * 题目:
 * 给你一个整数数组 arr ，请使用 煎饼翻转 完成对数组的排序。
 * 
 * 
 * State: Unresolved.
 * Tags: 排序
 * Link: https://leetcode-cn.com/problems/pancake-sorting/
 */

#include "../../Tools_function/head_cpp.h"

using namespace std;

vector<int> pancakeSort(vector<int>& arr)
{
    vector<int> rv;
    int len;
    int max_postion;

    len = arr.size();
    while (len > 0) {
        max_postion = max_element(arr.begin(), arr.begin() + len) - arr.begin();
        if (max_postion != len - 1) {
            reverse(arr.begin(), arr.begin() + max_postion + 1);
            reverse(arr.begin(), arr.begin() + len);
            rv.push_back(max_postion + 1);
            rv.push_back(len);
        }

        len--;
    }

    return rv;
}

int main()
{
    vector<int>arr {3, 2, 4, 1};
    vector<int>result;

    result = pancakeSort(arr);
    cout << "result vector:" << endl;
    for (auto num:result) {
        cout << num << " ";
    }

    cout << endl;
    return 0;
}