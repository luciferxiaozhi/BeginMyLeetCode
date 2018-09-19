# Leetcode Answers
## Tag: Array
### 832. Flipping an Image
Binary matrix, 
1. reverse
2. invert: 1 -> 0, 0 -> 1
#### Answer:
```
// reverse函数反转，再异或
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(auto & it : A) // reverse
        {
            reverse(it.begin(), it.end());
        }
            
        for(auto & row : A) // invert
        {
            for(auto & i : row)
            {
                i ^= 1; // xor
            }
        }
        return A;
    }
};
```

### 561. Array Partition I
Array of 2n integar,

n pairs (a1, b1) (a2, b2) (a3, b3) ...

max( sum( min(ai, bi) ) )

**Example1**:
```
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
```
#### Answer:
```
// 排序，每两个取一个，加起来。
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i += 2)
        {
                res += nums[i];
        }
        return res;
    }
};
```

### 867. Transpose Matrix
Transpose Matrix 翻转矩阵

Example1:
```
Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
```
#### Answer:
```
// 直接操作并翻转矩阵，交换i、j.
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if(A.empty()) return vector<vector<int>>();
        
        vector<vector<int>> res(A[0].size(), vector<int>());
        for(int i = 0; i < A.size(); i++)
        {
            for(int j = 0; j < A[i].size(); j++)
            {
                res[j].push_back(A[i][j]);
            }
        }
        return res;
    }
};
```

### 766. Toeplitz Matrix
判断矩阵每一斜着的列的元素，从左上到右下，元素值都相等。

**Example:**
```
Input:
matrix = [
  [1,2,3,4],
  [5,1,2,3],
  [9,5,1,2]
]
Output: True
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
```
#### Answer:
```
// personal approach
// 两个loop， 一个从左下到右下，一个从右上到右下，判断斜着的元素。
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {

        for(int i = 0; i < matrix[0].size(); i++) 
        {
          int r = matrix.size() - 1;
          int c = i;
            while(c > 0 && r > 0)
            {
                if(matrix[r][c] != matrix[r - 1][c - 1])
                {
                    return false;
                }
                c--;
                r--;
            }
        }

        for(int i = 0; i < matrix.size(); i++) 
        {
          int r = i;
          int c = matrix[0].size() - 1;
          while(c > 0 && r > 0)
          {
              if(matrix[r][c] != matrix[r - 1][c - 1])
              {
                  return false;
              }
              c--;
              r--;
          }
        }
        return true;
    }
};

// Approach 2:
// 判断每个元素左上的元素是否等于自己
// TC = O(M * N)  SC = O(1)
class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        for (int r = 0; r < matrix.length; ++r)
            for (int c = 0; c < matrix[0].length; ++c)
                if (r > 0 && c > 0 && matrix[r-1][c-1] != matrix[r][c])
                    return false;
        return true;
    }
}

// Approach 3:
// 同一斜列的x-y都相等，把(x-y, nums[x][y])存入hashmap， 判断如果
// 当前key的值跟hashmap中存的不一样，就false
// TC = O(M * N)  SC = O(M * N)
class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        Map<Integer, Integer> groups = new HashMap();
        for (int r = 0; r < matrix.length; ++r) {
            for (int c = 0; c < matrix[0].length; ++c) {
                if (!groups.containsKey(r-c))
                    groups.put(r-c, matrix[r][c]);
                else if (groups.get(r-c) != matrix[r][c])
                    return False;
            }
        }
        return True;
    }
}
```

### 566. Reshape the Matrix
将输入给的二维数组变为一维的。

**Example**：
```
Input: 
nums = 
[[1,2],
 [3,4]]
r = 1, c = 4
Output: 
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix,
fill it row by row by using the previous list.
```
#### Answer
```
// 用queue container，入队出队，进行变换。
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.empty()) return nums; // reshape is illegal
        if (nums.size() * nums[0].size() != r * c) return nums; // reshape is illegal
        
        vector<vector<int>> res(r, vector<int>(c, 0));
        
        queue<int> tmp;
        for(auto &row : nums)// enqueue
        {
            for(auto &col : row)
            {
                tmp.push(col);
            }
        }
        
        for(auto &row : res)
        {
            for(auto &col : row)
            {
                int value = tmp.front();
                tmp.pop();
                col = value;
            }
        }
        return res;
    }
};
```

### 896. Monotonic Array
momotonic：数组要么是不递减的，要么是不递增的。
#### Answer:
```
class Solution {
public:
    bool isMonotonic(vector<int>& A) 
    {
        return isIncreace(A) || isDecreace(A);
    }
    bool isIncreace(vector<int>& A)
    {
        for (int i = 0; i < A.size() - 1; i++)
        {
            if (A[i] > A[i + 1]) return false;
        }
        return true;
    }
    bool isDecreace(vector<int>& A)
    {
        for (int i = 0; i < A.size() - 1; i++)
        {
            if (A[i] < A[i + 1]) return false;
        }
        return true;
    }
};
```

### 888. Fair Candy Swap
两个数组，交换其中一个元素使得两数组的和相等。
#### Answer:
```
// A - x + y = B − y + x
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        // calculate sum of each array
        int sa = 0, sb = 0;
        for (auto & i : A) sa += i;
        for (auto & j : B) sb += j;
        int delta = (sb - sa) / 2;
        
        unordered_set<int> myset(B.begin(), B.end());
        for(int & x : A)
        {
            if(myset.find(x + delta) != myset.end())
            {
                return {x, x + delta};
            }
        }
    }
};
```

### 485. Max Consecutive Ones
找到最长1序列，1的个数。

**Example:**
```
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
```
#### Answer:
```
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1) count++;
            else count = 0;
            if (max < count) max = count;
        }
        return max;
    }
};
```

### 695. Max Area of Island
0代表海，连着的1代表岛，找到最大的岛并输出大小

**Example:**
```
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
```
#### Answer
```
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                    ans = max(ans, area(i, j, grid));
            }
        }
        return ans;
    }
    
    int area(int r, int c, vector<vector<int>>& grid)
    {
        if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() &&  grid[r][c] == 1)
        {
            grid[r][c] = 0;
            return (1 + area(r - 1, c, grid) + area(r, c - 1, grid) + area(r + 1, c, grid) + area(r, c + 1, grid));
        }
        return 0;
    }  
};
```

### 283. Move Zeroes
把所有的0都放在最后
#### Answer
```
// 两个指针i,j，把非零的都移到j，再把之后的都置为0.
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, j;
        for (i = 0, j = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                continue;
            nums[j] = nums[i];
            j++;
        }
        while(j < nums.size())
        {
            nums[j] = 0;
            j++;
        }
    }
};
```

### 448. Find All Numbers Disappeared in an Array
数组里元素范围[1, n], n是数组size。找到所有没有出现的元素。

#### Answer
```
// 将有的都变为负数，所有包含正数的index就是答案。
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            int m = abs(nums[i]) - 1; // m is from 0 to nums.size() - 1
            nums[m] = nums[m] > 0? -nums[m] : nums[m]; 
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
```

### 169. Majority Element
找到数组中出现最多的元素，出现大于[n/2]次。
#### Answer
```
// approach 1
// 直接构建hashmap进行计数，如果大于n/2，则return
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int & num : nums)
        {
            if (++count[num] > nums.size() / 2) return num;
        }
    }
};

// approach 2
// sort，然后第n/2（向下取整）一定是答案
```

### 122. Best Time to Buy and Sell Stock II
交易股票，可以交易很多次，找到最大的利润。

#### Answer
```
// 如果price[i]>price[i-1]则加上，否则就加0
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            ans += max(prices[i] - prices[i-1], 0);
        }
        return ans;
    }
};
```

### 717. 1-bit and 2-bit Characters
有两个字符，一个可以用0表示，另一个可以用10或11表示。

给一个字符串，最后总为0，请问它是否只能用一种字符表示？

#### Answer
```
// Approach 1
// 从倒数第二往前推，找连续的1的个数，如果是偶数个则true，否则false。
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int countOne= 0;
        for (int i = bits.size() - 2; i >= 0 && bits[i] != 0; i--)
        {
            countOne++;
        }
        if (countOne % 2 == 0) return true;
        else return false;
    }
};

// Approach 2(Python)
// 如果当前是0，那么下一个character一定有1bit，如果是1，那么下一个character一定有2bits。按照规则增加i，到最后判断是否是1bit的。
class Solution(object):
    def isOneBitCharacter(self, bits):
        i = 0
        while i < len(bits) - 1:
            i += bits[i] + 1
        return i == len(bits) - 1
```

### 217. Contains Duplicate
找数组中是否有重复的元素，重复则返回true。

#### Answer
```
// 构建一个set，如果size不一样则有重复的。
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> numsSet(nums.begin(), nums.end());
        if(nums.size() > numsSet.size()) return true;
        return false;
    }
};
```

### 167. Two Sum II - Input array is sorted
一个sorted的数组，找到其中两元素，和为target，返回他们的index。
#### Answer
```
// 二分查找
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0, hi = numbers.size() - 1;
        while (lo < hi)
        {
            if (numbers[lo] + numbers[hi] == target) return {lo+1, hi+1};
            else if(numbers[lo] + numbers[hi] < target) lo++;
            else hi--;
        }
    }
};
```

### 697. Degree of an Array
一个非空非负的数组，找到与他一样degree，长度最小的一个子数组，并返回其长度。

degree:某一元素出现的最高频率
#### Answer
```
// 建立一个hashmap（int nums[i], vector<int> indexes），将nums中相同值的元素的index存入
// 遍历寻找最大degree
// 从所有等于最大degree的vector中找到size最小的。

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]].push_back(i);
        int degree=0;
        for(auto it=mp.begin();it!=mp.end();it++) degree=max(degree,int(it->second.size()));
        int shortest=nums.size();
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second.size()==degree)
            {
                shortest=min(shortest,it->second.back()-it->second[0]+1);
            }
        }
        return shortest;
    }
};
```
### 830. Positions of Large Groups
一个string，找到其中连续出现3次及3次以上的字幕的起始终止位置。
#### Answer
```
// 计数，如果够3个了且下一个数不相等了就pushback，单独考虑结尾情况。
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ans;
        int count = 1;
        for (int i = 1; i < S.length() - 1; i++)
        {
            if (S[i] == S[i - 1])
            {
                count++;
                if (S[i] != S[i + 1] && count >= 3) // before length - 1
                {
                    ans.push_back({i - count + 1, i});
                }
                if (i == S.length() - 2 && S[i] == S[i + 1] && count >= 2) // length - 1
                {
                    ans.push_back({i - count + 1, S.length() - 1});
                }
            }
            else
            {
                count = 1;
            }
        }
        return ans;
    }
};
```

### 268. Missing Number
数组包含[0, n]元素， 找到缺失的那个元素
#### Answer
```
// Approach 1
// sorting and compare

// Approach 2
// build a hash set, then see if certain value is in the set or not

// Approach 3
// calculate sum from 0 to n, then return sum - sum(from nums[0] to nums[size() - 1])
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expectedNum = (nums.size() + 1) * nums.size() / 2;
        int actualNum = 0;
        for (int & num : nums)
        {
            actualNum += num;
        }
        return expectedNum - actualNum;
    }
};
```

### 628. Maximum Product of Three Numbers
找到数组中三个数乘积最大的三个数。
#### Answer
```
//找到最小的两个数，和最大的三个数，看是min1*min2*max1大还是max1*max2*max3大。
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        for (int & x : nums)
        {
            if (x <= min1)
            {
                min2 = min1;
                min1 = x;    
            }
            else if(x <= min2)
            {
                min2 = x;
            }
            
            if (x >= max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = x;
            }
            else if (x >= max2)
            {
                max3 = max2;
                max2 = x;
            }
            else if (x >= max3)
            {
                max3 = x;
            }
        }
        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};
```
### 121. Best Time to Buy and Sell Stock
只经历一次买卖，求最大profit
#### Answer
```
// 遍历寻找最小的price，并每次更新最大的profit
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minprice) minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
            {
                maxprofit = prices[i] - minprice;
            }
        }
        return maxprofit;
    }
};
```

### 746. Min Cost Climbing Stairs
从0或1开始，可以走一步也可以走两步，一直走到最后，问cost最少为多少。

#### Answer 
```
// 动态规划
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < dp.size(); i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[dp.size()-1], dp[dp.size()-2]);
    }
};
```

### 674. Longest Continuous Increasing Subsequence
给一个数组，找到最长持续递增子序列的长度
#### Answer
```
// anchor变量记录开始递增的开头，寻找最大递增长度。
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        int anchor = 0, ans = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] <= nums[i - 1]) anchor = i;
            ans = max(ans, i - anchor + 1);
        }
        return ans;
    }
};
```

### 118. Pascal's Triangle
输入层数，输出Pascal's Triangle
#### Answer
```
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> Array(numRows, vector<int>());
        //resize Array
        for (int i = 0; i < Array.size(); i++)
        {
            Array[i].resize(i+1, 1);
        }
        
        if(numRows > 2)
        {
            for (int i = 2; i < Array.size(); i++)
            {
                for (int j = 1; j < Array[i].size() - 1; j++)
                {
                    Array[i][j] = Array[i-1][j-1] + Array[i-1][j];
                }
            }
        }
        return Array;
    }
};
```
 
### 27. Remove Element
给数组和val，把等于val的移除，返回剩余元素个数并使得数组前几个元素为其他元素。
#### Answer
```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for(int j = 0; j < nums.size(); j++)
        {
            if(nums[j] != val)
            {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};
```

### 53. Maximum Subarray
找到连续的子序列，有着最大的sum
#### Answer
```
// dp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int maxSum = dp[0];
        for(int i = 1; i < nums.size(); i++)
        {
            dp[i] = nums[i] + max(dp[i - 1], 0);
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
};
```

### 747. Largest Number At Least Twice of Others
找到最大的数，如果这个数大于第二大数的两倍则return这个index，否则return -1
#### Answer
```
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN;
        int index;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > max1) 
            {
                max1 = nums[i];
                index = i;
            }
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == max1) continue;
            else if(nums[i] > max2) max2 = nums[i];
        }
        return max1 >= 2 * max2? index : -1;
    }
};
```

### 35. Search Insert Position
给一个排好序的数组和target，返回target可以插在哪。
#### Answer
```
// binary search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return lo;
    }
};
```

### 66. Plus One
给数组表示的数+1
#### Answer
```
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i = n - 1; i >= 0; i--)
        {
            if(i == 0 && digits[i] == 9)
            {
                digits[i] = 0;
                digits.insert(digits.begin(), 1);
                break;
            }
            if(digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i]++;
                break;
            }
        }
        return digits;
    }
};
```

### 119. Pascal's Triangle II
输入行数，输出此行的pascal'triangle的数组
#### Answer
```
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        for (int i = 1; i < res.size() - 1; i++)
        {
            for (int j = i; j >= 1; j--)
            {
                res[j] += res[j - 1];
            }
        }
        return res;
    }
};
```

### 724. Find Pivot Index
找到pivot，其左边元素加起来等于右边元素加起来
#### Answer
```
// leftSum == sum - nums[pivot] - leftSum
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0, sum = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (leftSum == sum - leftSum - nums[i]) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};
```

### 1. Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

**Example**:
```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```
#### Answer
```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> mymap;
        // build map
        for (int i = 0; i < nums.size(); i++)
        {
            mymap[nums[i]] = i;
        }
        // find complement
        for (int i = 0; i < nums.size(); i++)
        {
            int comp = target - nums[i];
            auto it = mymap.find(comp);
            if (it != mymap.end() && it->second != i)
            {
                res.push_back(it->second);
                res.push_back(i);
                return res;
            }
        }
    }
};
```

### 643. Maximum Average Subarray I
给个数组给个k，找到k长度的subarray拥有最大的平均值
#### Answer
```
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for(int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        double res = sum;
        for(int i = k; i < nums.size(); i++)
        {
            sum += nums[i] - nums[i - k];
            res = max(res, sum);
        }
        return res/k;
    }
};
```

### 849. Maximize Distance to Closest Person
1代表有人，0代表空座，找到一个座使得他离有人的座的距离最大,return 距离。

**Example**:
```
Input: [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
```
#### Answer
```
// 先考虑general情况，在分别从左右考虑
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int zeroCount = 0;
        int res = 0;
        int N = seats.size();
        for (int i = 0; i < N; i++)
        {
            if (seats[i] == 0)
            {
                zeroCount++;
            }
            else
            {
                res = max(res, (zeroCount + 1)/2);
                zeroCount = 0;
            }
        }
        for (int i = 0; i < N; i++)
        {
            if(seats[i] == 1)
            {
                res = max(res, i);
                break;
            }
        }
        for (int i = N - 1; i >= 0; i--)
        {
            if(seats[i] == 1)
            {
                res = max(res, N - 1 - i);
                break;
            }
        }
        return res;
    }
};
```

### 26. Remove Duplicates from Sorted Array
给一个排过序的数组，删除其中重复的元素,并返回长度。
#### Answer
```
// 两个指针
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int i,j;
        for (i = 1, j = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i - 1])
            {
                continue;
            }
            else
            {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};
```

### 840. Magic Squares In Grid
magic square是3x3数组，且里面元素是从1到9的,且行列斜着相加都相等，求给出的数组有多少个magic square。
#### Answer
```
// 垃圾题目
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size() < 3 || grid[0].size() < 3) return 0;
        int count = 0;
        for(int i = 0; i < grid.size() - 2; i++)
        {
            for(int j = 0; j < grid[0].size() - 2; j++)
            {
                if (grid[i+1][j+1] != 5) continue;
                if (isMagic(grid[i][j],grid[i][j+1],grid[i][j+2],
                           grid[i+1][j],grid[i+1][j+1],grid[i+1][j+2],
                           grid[i+2][j],grid[i+2][j+1],grid[i+2][j+2]))
                {
                    count++;
                }
            }
        }
        return count;
    }
    
    bool isMagic(int &a11, int &a12, int &a13, int &a21, int &a22, int &a23, int &a31, int &a32, int &a33)
    {
        vector<int> A(9,0);
        vector<int> array = {a11,a12,a13,a21,a22,a23,a31,a32,a33};
        for(int & item : array)
        {
            switch(item)
            {
                case 1: A[0] = 1;
                    break;
                case 2:A[1] = 1;
                    break;
                case 3:A[2] = 1;
                    break;
                case 4:A[3] = 1;
                    break;
                case 5:A[4] = 1;
                    break;
                case 6:A[5] = 1;
                    break;
                case 7:A[6] = 1;
                    break;
                case 8:A[7] = 1;
                    break;
                case 9:A[8] = 1;
                    break;
                default: break;
            }
        }
        for(int & item : A)
        {
            if(item == 0) return false;
        }
        return (
                a11+a12+a13 == 15 &&
                a21+a22+a23 == 15 &&
                a31+a32+a33 == 15 &&
                a11+a21+a31 == 15 &&
                a12+a22+a32 == 15 &&
                a13+a23+a33 == 15 &&
                a11+a22+a33 == 15 &&
                a31+a22+a13 == 15
               );
    }
};
```

### 219. Contains Duplicate II
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
#### Answer
```
// set s保留nums[i-k-1]到nums[i-1]的元素。
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> s;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > k) s.erase(nums[i-k-1]);
            if(s.find(nums[i]) != s.end()) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};
```

### 88. Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

#### Answer
```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, tar = m + n - 1;
        while(j >= 0)
        {
            nums1[tar--] = i >=0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--]; 
        }
    }
};
```

### 605. Can Place Flowers
0代表没种花的，1代表种花了的，花不能挨着中。给一个数n，问能否将n个花种进去。
**Example**:
```
Input: flowerbed = [1,0,0,0,1], n = 1
Output: True
```
#### Answer
```
// My solution - count continuous 0
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {        
        // all 0
        if(find(flowerbed.begin(), flowerbed.end(), 1) == flowerbed.end() && n <= (flowerbed.size() + 1) / 2) return true;

        
        int Ans = 0,count = 0;
        bool meetFlower = false;
        int last = 0;
        for(int i = flowerbed.size()-1; i >= 0; i--) // from back to last "one"
        {
            if(flowerbed[i] == 1)
            {
                last = i;
                Ans += (flowerbed.size() - 1 - last)/2;
                break;
            }
        }
        for(int i = 0; i <= last; i++) //from front to last
        {
            // before first flower
            if(flowerbed[i] == 0 && !meetFlower)
                count++;
            if(flowerbed[i] == 1 && !meetFlower)
            {
                Ans += count/2;
                meetFlower = true;
                count = 0;
            }
            // after first flower
            if(flowerbed[i] == 0 && meetFlower)
            {
                count++;
            }
            if(flowerbed[i] == 1 && meetFlower)
            {
                Ans += (count - 1) / 2;
                count = 0;
            }
        }
        return Ans >= n;
    }
};

// Approach 2
// when not the case, continue, else decrease n by 1. Finally, see if n == 0;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = (int)flowerbed.size();
        for (int i=0; i<flowerbed.size() && n>0; ++i) {
            if ((i && flowerbed[i-1] == 1) || flowerbed[i] == 1 || (i<m-1 && flowerbed[i+1]==1)) continue;
            flowerbed[i] = 1;
            --n;
        }
         return n==0;
    }
   
};
```

### 581. Shortest Unsorted Continuous Subarray
找到最短的子数组，如果你sort子数组那么整个数组也是sorted的了。
#### Answer
```

```












































