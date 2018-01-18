/*
********************************
Create by Shepherd Chang. 
Contents from leetcode.com
********************************
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

HINT: use stack
*/


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s)
        {
            if(c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else if(st.empty()) return false;
            else if(c == ')' && st.top() != '(') return false;
            else if(c == ']' && st.top() != '[') return false;
            else if(c == '}' && st.top() != '{') return false;
            else
            {
                st.pop();
            }

        }
        return st.empty();
    }
};











