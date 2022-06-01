#include<iostream>
#include<string.h>
using namespace std;

int main(){
    string A,B;
    int Da,Db;
    cin>>A>>Da>>B>>Db;
    int ac,bc;
    ac=bc=0;
    for(int i=0;i<A.size();i++){
        if(A[i]==Da+'0') ac++;
    }
    for(int j=0;j<B.size();j++){
        if(B[j]==Db+'0') bc++;
    }
    int sum1,sum2,sum;
    sum1=sum2=sum=0;
    while(ac>0){
        sum1=Da+sum1*10;
        ac--;
    }
    while(bc>0){
        sum2=Db+sum2*10;
        bc--;
    }
    sum=sum1+sum2;
    cout<<sum<<endl;
    return 0;
}