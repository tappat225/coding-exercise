#include<iostream>
using namespace std;
int main(){
    int a[56],x;
    a[1]=1;a[2]=2;a[3]=3;a[4]=4;a[5]=6;
    for(int i=6;i<=55;i++){
        a[i]=a[i-1]+a[i-3];
    }
    while(cin>>x){
        cout<<a[x]<<endl;
    }
    return 0;
}