/*
********************************
Create by Shepherd Chang. 
Contents from leetcode.com
********************************
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

Hint: use hashmap function find.

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> HashMap;
        for(int i = 0; i < nums.size(); i++)
        {
            int num2 = target - nums[i];
            if(HashMap.find(num2) != HashMap.end())
            {
                result.push_back(HashMap[num2]);
                result.push_back(i);
                return result;
            }

            HashMap[nums[i]] = i;
        }
        return result;
    }
};