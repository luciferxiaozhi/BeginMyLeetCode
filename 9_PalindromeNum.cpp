/*
********************************
Create by Shepherd Chang. 
Contents from leetcode.com
********************************
Determine whether an integer is a palindrome. Do this without extra space.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. 
However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. 
How would you handle such case?

There is a more generic way of solving this problem.

*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x != 0 && x % 10 == 0)) return false;
        int halfRervNum = 0;
        while(halfRervNum < x) // Compare half digit of that number
        {
            halfRervNum = halfRervNum * 10 + x % 10;
            x /= 10;
        }
        return (x == halfRervNum) || (x == halfRervNum / 10); // case 1: 123321,  case 2: 1234321
    }
};









