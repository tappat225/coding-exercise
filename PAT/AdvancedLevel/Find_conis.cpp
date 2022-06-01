/**
 * Title: N_AZ1037 Find Coins
 * 
 * 
 * 
 * Link: https://www.nowcoder.com/pat/5/problem/4087
 * 
 * State: Passed.
 * 
*/
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    int a[N];
    for (int i = 0; i < N; i++){
        cin>>a[i];
    }
    sort(a,a+N);
    int flag=N-1;
    for(int j=N-1;j>0;j--){
        if(a[j]<=M) {flag=j;break;}
    }
    int ans1,ans2;
    ans1=ans2=-1;
    /*O(n^2),test failed for surpass limited time*/
    /*int bflag=0;
    for(int k=0;k<=flag;k++){
        for(int p=k+1;p<=flag;p++){
            if(a[k]+a[p]==M){
                ans1=a[k];
                ans2=a[p];
                bflag=1;
                break;
            }
        }
        if(bflag==1) break;
    }
    */
    int low,high;
    low=0;high=flag;
    while(low<high){
        if(a[low]+a[high]>M) high--;
        else if(a[low]+a[high]==M) {
            ans1=a[low];
            ans2=a[high];
            break;
        }
        else low++; 
    }

    if(ans1==-1||ans2==-1){
        cout<<"No Solution"<<endl;
    }
    else{
        cout<<ans1<<' '<<ans2<<endl;
    }
    /*for(int w=0;w<N;w++){
        cout<<a[w]<<' ';
    }
    cout<<endl;*/
    return 0;
}