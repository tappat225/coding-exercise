/****************
// 题目描述
哈夫曼树，第一行输入一个数n，表示叶结点的个数。
需要用这些叶结点生成哈夫曼树，根据哈夫曼树的概念，这些结点有权值，即weight，
题目需要输出所有结点的值与权值的乘积之和。
// 输入描述:
输入有多组数据。
每组第一行输入一个数n，接着输入n个叶节点（叶节点权值不超过100，2<=n<=1000）。
// 输出描述:
输出权值。
********************/

#include<bits/stdc++.h>
using namespace std;

// struct Htree{
//     int value;
//     struct Htree *lchild;
//     struct Htree *rchild;
// }*Hnode;

int main(){
    priority_queue<int,vector<int>,greater<int>>l;
    int n;
    while(cin>>n){
        int temp;
        int weight,nsum;
        weight=0; //这一步没初始化的话会错误
        int num1,num2;
        for(int i=0;i<n;i++){
            cin>>temp;
            l.push(temp);
        }
        while(l.size()!=1){
            num1=l.top();
            l.pop();
            num2=l.top();
            l.pop();
            nsum=num1+num2;
            weight+=nsum;
            l.push(nsum);
        }
        cout<<weight<<endl;
    }
    return 0;
}
