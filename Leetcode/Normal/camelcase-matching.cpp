/**
 * @file camelcase-matching.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-14
 * 
 * @copyright Copyright (c) 2023
 * @link https://leetcode.cn/problems/camelcase-matching/description/
 * @tag: 链表
 * @state: Unresolved.
 * @Feeling 
 */

#include "../../Tools_function/head_cpp.h"

using namespace std;

class Solution {
public:
    set<char> upperElemTable;

    void setTableElem(string s1, int index, set<char> &e) {
        if (isupper(s1[index]) != true) {
            return;
        }

        e.insert(s1[index]);
    }

    bool pairFunction(string qElem, string pattern) {
        bool flag = false;


        return flag;
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;

        for (int i = 0; i < pattern.length() ; i++) {
            setTableElem(pattern, i, upperElemTable);
        }

        return ans;
    }
};
