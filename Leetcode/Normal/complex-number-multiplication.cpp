/**
 * 字符串形式输入两个复数，字符串形式返回它们的乘积。
 * 
 * 
 * Tags: sscanf应用，格式化输入
 * Link: https://leetcode-cn.com/problems/complex-number-multiplication/
 * 
 * Feeling: 自己的想法过于复杂，想着对输入格式做逐个分析
 */

#include "../../Tools_function/head_cpp.h"

using namespace std;

#ifdef SB_METHOD
/* 过于繁琐冗长 */
int sign_count = 0;

struct comlex_num {
    int pnum;
    int nnum;
};

struct comlex_num convert_num(string num)
{
    struct comlex_num this_num = {0 ,0};
    bool n_flag;
    bool n_sign;
    bool first_n_sign;

    n_flag = false;
    n_sign = false;
    first_n_sign = false;
    for (int i = 0; i < num.size(); i++) {
        if (i == 0 && num[i] == '-') {
            first_n_sign = true;
            continue;
        }

        if (num[i] == 'i') {
            break;
        }

        if (num[i] == '+') {
            n_flag = true;
            sign_count++;
            continue;
        }

        if (num[i] == '-') {
            n_flag = true;
            n_sign = true;
            sign_count++;
            continue;
        }

        if (n_flag == true) {
            this_num.nnum = this_num.nnum * 10 + num[i] - '0';
        } else {
            this_num.pnum = this_num.pnum * 10 + num[i] - '0';
        }
    }

    this_num.nnum = (n_sign) ? (-this_num.nnum) : (this_num.nnum);

    return this_num;
}

string convert_string(struct comlex_num num)
{
    string num_str;

    num_str += to_string(num.pnum);
    if (sign_count > 1) {
        num_str += '+';
    }

    num_str += to_string(num.nnum);
    num_str += 'i';

    return num_str;
}

string complexNumberMultiply(string num1, string num2)
{
    struct comlex_num this_num1;
    struct comlex_num this_num2;
    struct comlex_num result_num;

    this_num1 = convert_num(num1);
    this_num2 = convert_num(num2);
    result_num.pnum = this_num1.pnum * this_num2.pnum - this_num1.nnum * this_num2.nnum;
    result_num.nnum = this_num1.pnum * this_num2.nnum + this_num1.nnum * this_num2.pnum;

    return convert_string(result_num);
}

#else
/* sscanf的强大应用例 */
string complexNumberMultiply(string num1, string num2)
{
    int a, b, c, d;

    sscanf(num1.c_str(), "%d+%di", &a, &b);
    sscanf(num2.c_str(), "%d+%di", &c, &d);

    int pnum = a * c - b * d;
    int nnum = a * d + b * c;

    return string(to_string(pnum) + "+" + to_string(nnum) + "i");
}

#endif

int main()
{
    string test_num1;
    string test_num2;

    cout << "Input two string: ";
    cin >> test_num1;
    cin >> test_num2;
    cout << complexNumberMultiply(test_num1, test_num2) << endl;
    return 0;
}
