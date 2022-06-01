#include<iostream>
using namespace std;

int main(){
    long n;
    
    while(cin>>n){
        long sum=1;
        int count=0;
        if(n>=1){
            while(sum<n){
                sum*=3;
                ++count;
            }
        
       // else if(n==1) count=0;
        cout<<count<<endl;
        }
    }

    return 0;
}