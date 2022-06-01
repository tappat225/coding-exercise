/**
 * @file longest-substring-without-repeating-characters.cpp
 * 
 * @author your name (you@domain.com)
 * @brief 求字符串的最长无重复子串长度，注意字符串s由英文字母、数字、符号和空格组成
 * @version 0.1
 * @date 2022-05-19
 * 
 * @copyright Copyright (c) 2022
 * @link https://leetcode.cn/problems/longest-substring-without-repeating-characters/
 * @feelings: 一眼哈希，结果做出来效率太低了，不过用哈希是对的，如何处理子串窗口是重点
 */

#include "../../Tools_function/head_cpp.h"

using namespace std;

#define DP

#ifdef MY_SOLUTION

/**
 * 执行用时：140 ms, 在所有 C++ 提交中击败了8.73%的用户
 * 内存消耗：311.8 MB, 在所有 C++ 提交中击败了4.96%的用户
 */

int get_next_start(string s, char hit_char, int cur_pos)
{
    for (int i = cur_pos - 1; i >= 0; i--) {
        if (s[i] == hit_char) {
            return i;
        }
    }

    return 0;
}

int lengthOfLongestSubstring(string s)
{
    int hash_table[128] = {0};
    int max_len = 0;
    int len = 0;
    int offset;

    for (size_t i = 0; i < s.size(); i++) {
        offset = (int)s[i];
        hash_table[offset]++;
        len++;
        if (hash_table[offset] > 1) {
            max_len = (max_len < (len - 1)) ? (len - 1) : max_len;
            len = 0;
            memset(hash_table, 0, sizeof(hash_table));
            i = get_next_start(s, s[i], i);     /* 其实没必要返回到起始位扫描，只要得到左边界然后用右边界相减再与最长len比较即可 */
        }
    }

    max_len = (max_len < len) ? len : max_len;
    return max_len;
}

#endif

#ifdef DP

/**
 * 执行用时: 0 ms
 * 内存消耗: 7.4 MB 
 */

/**
 * @brief 
 * @describe DP算法，维护一个128长度的数组存放字符第一次出现的位置
 * @param s 
 * @return int 
 */
int lengthOfLongestSubstring(string s)
{
    vector<int> pos_table(128, -1);
    int max_len = 0;
    int i = 0;
    int start = 0;
    int len = (int)s.size();

    /*
     * 遍历一遍，采用窗口的思想，窗口右边界一直是i，左边界由哈希判断确定
     */
    while (i < len) {
        start = max(start, pos_table[s[i]] + 1);    /* 此处为精髓，判断了哈希的同时更新起始位置 */
        max_len = max(max_len, i - start + 1);
        pos_table[s[i]] = i;
        i++;
    }

    return max_len;
}

#endif

int main()
{
    string s;

    cout << "Input string: ";
    getline(cin, s);
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
