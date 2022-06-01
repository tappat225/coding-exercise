/* 
 * Given an integer x, return true if x is palindrome integer.
 * An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.
 * 
 * Link: https://leetcode-cn.com/problems/palindrome-number/
 * 
 * State: Passed.
 * 
*/

#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
    int rev_x;
    int ori_x;
    
    ori_x = x;
    rev_x = 0;
    if (x < 0) {
        return false;
    }

    while (ori_x) {
        rev_x *= 10;
        rev_x += + ori_x % 10;
        ori_x /= 10;
    }

    if (x == rev_x) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    int num;

    printf("Input a num: ");
    scanf("%d", &num);
    printf("num is %s \n", (isPalindrome(num) ? "Palindrome" : "not Palindrome"));
    return 0;
}
