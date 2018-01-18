/*
********************************
Create by Shepherd Chang. 
Contents from leetcode.com
********************************
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int h = haystack.size();
        if(needle.empty()) return 0;
        for(int i = 0; i <  h - n + 1; i++)
        {
            int j = i;
            for(; j < n+i; j++)
            {
                if(needle[j-i] != haystack[j]) break;
            }
            if(j == n + i) return i;
        }
        return -1;
    }
};