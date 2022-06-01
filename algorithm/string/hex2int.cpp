/**
 * 输入十六进制数字符串，转成十进制输出
 * 
 * 十六进制以0x或0X开头
 * 
 * 输入例：
 * 0xAA
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

int hex2int_bit(char c)
{
    if (isdigit(c)) {
        return (c - '0');
    }

    switch (c) {
    case 'A':
    case 'a':
        return 10;
        break;
    case 'B':
    case 'b':
        return 11;
        break;
    case 'C':
    case 'c':
        return 12;
        break;
    case 'D':
    case 'd':
        return 13;
        break;
    case 'E':
    case 'e':
        return 14;
        break;
    case 'F':
    case 'f':
        return 15;
        break;
    default:
        return -1;
        break;
    }

    return 0;
}

bool hex2int(string s, int *num)
{
    int num_len = s.size() - 3;
    int sum = 0;

    if (s[0] != '0') {
        return false;
    }

    if (s[1] != 'x') {
        if (s[1] != 'X') {
            return false;
        }
    }

    for (int i = 2; i < s.size(); i++) {
        int bit_num = hex2int_bit(s[i]);
        if (bit_num < 0) {
            return false;
        }

        sum += bit_num * pow(16, num_len);
        num_len--;
    }

    *num = sum;
    return true;
}

int main()
{
    string s_in{"0XAAA"};
    int num = -1;

    if (hex2int(s_in, &num) != true) {
        cout << "invalid num" << endl;
        return 0;
    }

    cout << num << endl;

    return 0;
}
