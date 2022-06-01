#include <bits/stdc++.h>
using namespace std;
//哈夫曼树类问题
int main()
{
    priority_queue< int, vector<int>, greater<int> > l;   //最小值优先队列
    int n, temp;
    cin >> n;   //输入结点的个数n
    for (int i = 0; i < n; i++)
    {
        cin >> temp;     //输入n个叶结点
        l.push(temp);    //叶结点入队操作
    }
    int sum = 0;
    while(l.size() != 1)   //当结点大小不为1时
    {
        //取出队列中的最小的元素
        int min1 = l.top();
        l.pop();
        //取出队列中的次最小的元素
        int min2 = l.top();
        l.pop();
        //计算最小值和次最小值的权值
        sum += min1 + min2;
        l.push(min1+min2);  //入队列
    }
    cout << sum << endl;
    return 0;
}