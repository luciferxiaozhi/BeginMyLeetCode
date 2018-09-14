/*
********************************
Create by Shepherd Chang. 
Contents from leetcode.com
********************************

Write a function to find the longest common prefix string amongst an array of strings.

最长公共前缀
Hint: 
Compare all other elements in strs[i][k], i from 1 to strs[0].size() with strs[0][k]. 
If not equal, return the saved value, else append until not.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        if(strs.size() == 0) return result;
        for(int k = 0; k < strs[0].size(); k++)
        {
            int i = 1;
            for(; i < strs.size();i++)
            {
                if(strs[i][k] != strs[0][k]) return result;
            }
            result+=strs[0][k];
        }
        return result;
    }
};