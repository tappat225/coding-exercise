#include<iostream>
#include<cstring>
using namespace std;
//hahahahah
int main(){
    int n,m;
    while(cin>>n>>m){
    string s;
    while(n>0){
        if(n%m<10){
            s+='0'+n%m;
        }
        else {s+='A'+n%m-10;}
        n=n/m;
    }
    for(int i=s.size()-1;i>=0;i--){
        cout<<s[i];
    }
    cout<<endl;
    }
    return 0;
}