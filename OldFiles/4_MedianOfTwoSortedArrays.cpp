/*
********************************
Create by Shepherd Chang. 
Contents from leetcode.com
********************************

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

Solution discription: https://leetcode.com/problems/median-of-two-sorted-arrays/solution/
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n)
        {
            vector<int> temp = nums1; nums1 = nums2; nums2 = temp;
            int tmp = m; m = n; n = tmp;
        }
        int iMin = 0, iMax = m;
        while(iMin <= iMax)
        {
            int i = (iMin + iMax) / 2;
            int j = (m + n + 1)/2 - i;
            if(j > 0 && i < m && nums2[j-1] > nums1[i]) //i is too small
            {
                iMin++;
            }
            else if(i > 0 && j < n && nums1[i-1] > nums2[j])// i is too large
            {
                iMax--;
            }
            else
            {
                int maxLeft = 0;
                if(i == 0) {maxLeft = nums2[j-1];}
                else if(j == 0) {maxLeft = nums1[i-1];}
                else {maxLeft = max(nums1[i-1], nums2[j-1]);}
                if((m + n) % 2 == 1) return maxLeft;

                int minRight = 0;
                if(i == m) {minRight = nums2[j];}
                else if(j == n) {minRight = nums1[i];}
                else {minRight = min(nums1[i], nums2[j]);}

                return (double)(maxLeft+minRight) / 2;
            }
        }
    }
};