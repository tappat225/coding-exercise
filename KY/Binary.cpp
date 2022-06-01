/*************************
 * 大家都知道，数据在计算机里中存储是以二进制的形式存储的。 
 * 有一天，小明学了C语言之后，他想知道一个类型为unsigned int 类型的数字，
 * 存储在计算机中的二进制串是什么样子的。 
 * 你能帮帮小明吗？并且，小明不想要二进制串中前面的没有意义的0串，即要去掉前导0。
 * 
 * 输入描述:
 *每行有一个数字n（0<=n<=10^8），表示要求的二进制串。
 * 
 * 输出描述:
 *输出共T行。每行输出求得的二进制串。
 * 
 * *************************/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    while(T){
        unsigned int num;
        scanf("%d",&num);
        vector<int> s;
        while(num>0){
            int temp=num&1;
            s.push_back(temp);
            num=num>>1;
        }
        for(int i=s.size()-1;i>=0;i--){
            printf("%d",s[i]);
        }
        printf("\n");
        T--;
    }
    return 0;
}





/*********************
 * version 1.0 超时
// int main(){
//     int T;
//     unsigned int num;
//     cin>>T;
//     while(T){
//         cin>>num;
//         stack<int> s;
//         while(num>0){
//             int temp=num%2;
//             s.push(temp);
//             num=num/2;
//         }
//         while(s.size()>=1){
//             cout<<s.top();
//             s.pop();
//         }
//         cout<<endl;
//         T--;
//     }
//     return 0;
// }
******************************/
