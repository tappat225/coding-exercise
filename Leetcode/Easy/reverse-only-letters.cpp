/**
 * 
 * State: Resolved.
 * Tags: 字符串，栈
 * Link: https://leetcode-cn.com/problems/reverse-only-letters/
 */

#include "../../Tools_function/head_cpp.h"

#include<stack>
#include<queue>

using namespace std;

bool is_alphab(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

string reverseOnlyLetters(string s)
{
    stack<char> letter;
    for (auto &l:s) {
        if (is_alphab(l)) {
            letter.push(l);
            l = ' ';
        }
    }

    for (auto &l:s) {
        if (l == ' ') {
            l = letter.top();
            letter.pop();
        }
    }

    return s;
}

int main()
{
    string s = "abc.ab";

    cout << reverseOnlyLetters(s) << endl;
    return 0;
}
