#include<iostream>
#include<cstring>
using namespace std;

int main(){
    string s;
    while(cin>>s){
        int a[10]={0};
        int max=0;
        int maxk;
        for(int i=0;i<s.size();i++){
            int k=0;
            k=s[i]-'0';
            ++a[k];
            if(a[k]>max) {max=a[k];}
        }
        while(max>0){
            for(int p=0;p<10;p++){
                if(a[p]==max){
                    cout<<'*';
                    a[p]--;
                }
                else cout<<' ';
            }
            max--;
            cout<<endl;
        }
        cout<<"0123456789"<<endl;
    }
    return 0;
}