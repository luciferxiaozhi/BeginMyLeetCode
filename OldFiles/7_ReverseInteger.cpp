/*
********************************
Create by Shepherd Chang. 
Contents from leetcode.com
********************************
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output:  321

Example 2:

Input: -123
Output: -321

Example 3:

Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

*/

class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while(x)
        {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return (res > INT_MAX || res < INT_MIN)?0:res; // 1. INT_MAX/ INT_MIN need include<limits.h> 2. When reversing, the value may overflow.
    }
};






