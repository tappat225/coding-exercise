#include<iostream>
using namespace std;

int main(){
    long long a[91];
    a[1]=1;
    a[2]=2;
    for(int i=3;i<91;i++){
        a[i]=a[i-1]+a[i-2];
    }
    int n;
    while(cin>>n){
    cout<<a[n]<<endl;
    }
    return 0;
}