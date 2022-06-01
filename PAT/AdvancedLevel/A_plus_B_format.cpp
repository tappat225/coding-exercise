/**
 * Title: N_A1013 A+B Format
 * 
 * Calculate a + b and output the sum in standard format -- that is,
 * the digits must be separated into groups of three by commas (unless there are less than four digits).
 * 
 * Input description:
 * Each input file contains one test case.
 * Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000.
 * The numbers are separated by a space.
 * 
 * Output description:
 * For each test case, you should output the sum of a and b in one line.
 * The sum must be written in the standard format.
 * 
 * Input case:
 * -1000000 9
 * 
 * Output case:
 * -999,991
 * 
 * Link: https://www.nowcoder.com/pat/1/problem/4003
 * 
 * State: Passed.
 * 
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    int A,B;
    int SUM;
    string s;
    int flag = 1;
    int count = 1;
    cin>>A>>B;
    SUM = A + B;
    if (SUM < 0) {
        SUM = -SUM;
        flag = -1;
    }

    while (SUM > 0) {
        s += '0' + SUM % 10;
        if(count == 3 && SUM > 10) {
            s += ',';
            count = 0;
        }

        SUM = SUM / 10;
        count++;
    }

    if (flag == -1) {
        s += '-';
    }

    reverse(s.begin(),s.end());
    cout<<s<<endl;
    return 0;
}
