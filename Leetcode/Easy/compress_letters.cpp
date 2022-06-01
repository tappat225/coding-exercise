/**
 * @file compress_letters.cpp
 * 
 * @author your name (you@domain.com)
 * @brief 压缩字母，例如把aaaeesss压缩成a3e2s3
 * @version 0.1
 * @date 2022-05-03
 * 
 * @copyright Copyright (c) 2022
 * @link https://www.lintcode.com/problem/213/?utm_source=sc-zhihu-sy1206-2
 */

#include "../../Tools_function/head_cpp.h"

using namespace std;

string compress(string &originalString)
{
    int count;
    string res;

    count = 0;
    for (int i = 0; i < originalString.size(); i++) {
        count++;
        if (originalString[i] != originalString[i + 1]) {
            res += originalString[i];
            res += to_string(count);
            count = 0;
        }
    }

    if (res.size() >= originalString.size()) {
        return originalString;
    }

    return res;
}

int main()
{
    string s1;

    cin >> s1;
    cout << compress(s1) << endl;

    return 0;
}

