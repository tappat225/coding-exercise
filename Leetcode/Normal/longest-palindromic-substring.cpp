
/**
 * @file longest-palindromic-substring.cpp
 * @author your name (you@domain.com)
 * @brief 给一个字符串，找出最长回文子串，注意，不是回文子序列，子串要求是连续的
 * @version 0.1
 * @date 2022-05-18
 * 
 * @copyright Copyright (c) 2022
 * @Link: https://leetcode.cn/problems/longest-palindromic-substring/
 * @state: Resolved.
 */
#include "../../Tools_function/head_cpp.h"

using namespace std;

/* 中心扩散简洁版 */
string longestPalindrome(string s)
{
    int start = 0, end = 0;

    for (int i = 0; i < (2 * s.size() - 1); i++) {
        int l = i / 2;
        int r = i / 2 + i % 2;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            if ((r - l) > (end - start)) {
                start = l;
                end = r;
            }

            l--;
            r++;
        }
    }

    string res;
    for (int i = start; i <= end; i++) {
        res.push_back(s[i]);
    }

    return res;
}

int main()
{
    string s{"hello"};
    cout << longestPalindrome(s) << endl;

    return 0;
}
