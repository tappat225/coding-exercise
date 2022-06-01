/* 
*正整数n是两个不同质数的乘积，求较大的那个质数。 
*
*输入：
*每组输入数据只有一行，包含一个正整数n。
*数据规模：
*对于60%的数据，6≤n≤1000。
*对于100%的数据，6≤n≤2e9。
*
*
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main() {
    int n,i;
    int BGnum=1;
    scanf("%d",&n);
    const int maxn = n/2;
    for(i = 2;i <= maxn;i++) {
        if(n%i == 0) {
            n = n/i;
            if(i > BGnum) {
                BGnum = i;
            }
            // i--;
        }
    }
    printf("%d\n",BGnum);
    return 0;
}