/* 验证给定的字符串是否可以解释为十进制数字。
例如:
"0" => 1
"0.1" => 1
"abc" => 0
"1 a" => 0
"2e10" => 1
"-90e3" => 1
"1e" => 0
"e3" => 0
"6e-1" => 1
"99e2.5 " => 0
"53.5e93" => 1
"--6 " => 0
"-+3" => 0
"95a54e53" => 0

你应当考虑所有可能的情况。这里给出一份有效十进制数字中的字符列表：

    数字 0-9
    指数 - "e"
    正/负号 - "+"/"-"
    小数点 - "."

在输入中这些字符的上下文也很重要。

易错的用例：
    1 ：".1"  "-.1"  "1."  "005047e+6"  "46.e3"  ".2e81"
    0："."  "+e"


备注
1  根据题意  .1 、 -.1、 .2e81 是前面0省略，也算合法数字
2  十进制数字前后有空格，也是认为是合法的十进制数字 */



#include<stdio.h>
#include<stdbool.h>

static bool isDigit(char c){
    return c >= '0' && c <= '9';
}

static int isNumber(char * s){
    int i = 0;
    
    //skip spaces
    while (s[i] && s[i]==' ') i++;
    if (s[i] == 0) return 0;
    
    //skip first pos/neg sign
    if (s[i]=='+' || s[i]=='-') i++;
    
    //the next symbol is allowed to be a digit or a dec.point
    if (!isDigit(s[i]) && s[i]!='.') return 0;
    
    int containsDigits = 0;
    int containsDecPoint = 0;
    while (isDigit(s[i]) || s[i]=='.'){
        if (isDigit(s[i])) containsDigits = 1;   
        if (s[i]=='.') {
            //it is allowed to have only one dec.point
            if (containsDecPoint) return 0;
            containsDecPoint = 1;
        }
        i++;
    }
    //if we don't have any digits in our number it is not valid
    if (!containsDigits) return 0;
    
    //here and only here we're allowed to have an exp.sign
    if (s[i]=='e'){
        i++;
        if (s[i]=='-' || s[i]=='+') i++;
        //digits after the exp.sign are necessarily
        if (!isDigit(s[i])) return 0;
        while (isDigit(s[i])) i++;
    }
    
    //ending spaces
    while (s[i]==' ') i++;
    //now we must have reached the end of the string
    if (s[i] != 0) return 0;
    
    return 1;
}

int main(){
    char str[20];
    scanf("%s",str);
    printf("%d\n",isNumber(str));
    return 0;
}