/*
*题目：输入任意（用户，成绩）序列，可以获得成绩从高到低或从低到高的排列,相同成绩
*都按先录入排列在前的规则处理。
**************************
*排序方式：冒泡。
* 难点：要求相同分数不论降序升序均按输入时的顺序输出。
*/

#include<stdio.h>

typedef struct student{
    char name[100];
    int score;
}stu;

void sort(stu *s,int num){
    int m,n;
    n=num;
    stu temp;
    while(n){
        for(m=0;m<n-1;m++){
            if(s[m+1].score<s[m].score){
                temp=s[m+1];
                s[m+1]=s[m];
                s[m]=temp;
            }
        }
        n--;
    }
}

void sort_down(stu *s,int num){
    int m,n;
    n=num;
    stu temp;
    while(n){
        for(m=0;m<n-1;m++){
            if(s[m+1].score>s[m].score){
                temp=s[m+1];
                s[m+1]=s[m];
                s[m]=temp;
            }
        }
        n--;
    }
}

int main(){
    int num,model;
    while(scanf("%d%d",&num,&model)!=EOF){
        int i;
        stu s[num];
        for(i=0;i<num;i++){
            scanf("%s%d",&s[i].name,&s[i].score);
        }
        
        if(model==1){
            sort_up(s,num);
            
        }
        else{
            sort_down(s,num);
        }
        for(i=0;i<num;i++){
                printf("%s %d\n",s[i].name,s[i].score);
            }
    }
    return 0;
}