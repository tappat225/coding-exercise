#include<iostream>
#include<cstring>
using namespace std;
int main(){
    long long A,B,SUM;
    int D;
    string s;
    cin>>A>>B>>D;
    SUM=A+B;
    while(SUM>0){
        s+='0'+SUM%D;
        SUM=SUM/D;
    }
    for(int i=s.size()-1;i>=0;i--){
        cout<<s[i];
    }
    cout<<endl;
    return 0;
}