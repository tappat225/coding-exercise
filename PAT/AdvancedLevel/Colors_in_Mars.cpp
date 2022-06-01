/**
 * Title: N_A1006 Colors in Mars
 * 
 * People in Mars represent the colors in their computers in a similar way as the Earth people.
 * 
 * That is, a color is represented by a 6-digit number, where the first 2 digits are for Red,
 * the middle 2 digits for Green, and the last 2 digits  for Blue. 
 * The only difference is that they use radix 13 (0-9 and A-C) instead of 16.
 * 
 * Now given a color in three decimal numbers (each between 0 and 168), you are supposed to output their Mars RGB values.
 * 
 * Input description:
 * Each input file contains one test case which occupies a line containing the three decimal color values.
 * 
 * Output description:
 * For each test case you should output the Mars RGB value in the following format: first output "#",
 * then followed by a 6-digit number where all the English characters must be upper-cased.
 * If a single color is only 1-digit long, you must print a "0" to the left.
 * 
 * Input example:
 * 15 43 71
 * 
 * Output example:
 * #123456
 * 
 * Link: https://www.nowcoder.com/pat/1/problem/4014
 * 
 * State: Passed.
*/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

void Trans(int RGB,string &s){
    while(RGB>0){
        if(RGB%13<10){
            s+='0'+RGB%13;
        }
        else{
            s+='A'+RGB%13-10;
        }
        RGB=RGB/13;
    }

    if(s[1]==NULL){
        s+='0';
    }
}

int main(){
    int R,G,B;
    string s1,s2,s3,s;
    cin>>R>>G>>B;
    s+='#';
    Trans(R,s1);
    Trans(G,s2);
    Trans(B,s3);
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    reverse(s3.begin(),s3.end());
    s+=s1+s2+s3;
    cout<<s<<endl;
    return 0;
}
