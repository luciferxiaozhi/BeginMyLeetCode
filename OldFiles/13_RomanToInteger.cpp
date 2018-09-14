/*
********************************
Create by Shepherd Chang. 
Contents from leetcode.com
********************************
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Hint:
I: 1
V: 5
X: 10
L: 50
C: 100
D: 500
M: 1000
*/

class Solution {
public:
    int roman(string::iterator c)
    {
        switch(*c)
        {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
    int romanToInt(string s) {
        int sum = 0;
        for(string::iterator it = s.begin(); it!=s.end(); ++it)
        {
            int cur = roman(it);
            int next = roman(it + 1);
            if(cur < next)
                sum -= cur;
            else
                sum += cur;
        }
        return sum;
    }
};