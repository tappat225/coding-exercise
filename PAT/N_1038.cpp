#include<iostream>
using namespace std;

int main(){
    string s[30];
    int x;
    cin>>x;
    int ge=x%100;
    int shi=x/10%10;
    int bai=x/100;
    for (int i = 0; i < bai; i++)
    {
        s[i]='B';
    }
    for (int j = 0; j < shi; j++)
    {
        s[bai+j]='S';
    }
    for (int k = 0; k < ge; k++)
    {
        s[bai+shi+k]='1'+k;
    }
    cout<<s<<endl;
    return 0;
    
}