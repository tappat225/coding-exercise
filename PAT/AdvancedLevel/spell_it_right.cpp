/**
 * Title: N_A1017 Spell It Right
 * 
 * Given a non-negative integer N, your task is to compute the sum of all the digits of N,
 * and output every digit of the sum in English.
 * 
 * Input:
 * Each input file contains one test case. Each case occupies one line which contains an N (<= 10100).
 * 
 * Output:
 * For each test case, output in one line the digits of the sum in English words.
 * There must be one space between two consecutive words, but no extra space at the end of a line.
 * 
 * Input case:
 * 12345
 * 
 * Output case:
 * one five
 * 
 * Link: https://www.nowcoder.com/pat/1/problem/3999
 * 
 * State: Passed.
 * 
*/

#include<iostream>
#include<cstring>
using namespace std;

int main(){
    string N;
    int sum=0;
    cin>>N;
    string s,ans;
    for(int j=0;j<N.size();j++){
        sum+=N[j]-'0';
    }

    while(sum>0){
        s+='0'+sum%10;
        sum=sum/10;
    }

    for (int i = s.size()-1; i >= 0; i--) {
        switch (s[i]) {
        case '0':ans+="zero";break;
        case '1':ans+="one";break;
        case '2':ans+="two";break;
        case '3':ans+="three";break;
        case '4':ans+="four";break;
        case '5':ans+="five";break;
        case '6':ans+="six";break;
        case '7':ans+="seven";break;
        case '8':ans+="eight";break;
        case '9':ans+="nine";break;
        default:
            break;
        }

        ans += ' ';
    }

    cout<<ans<<endl;
    return 0;
}
