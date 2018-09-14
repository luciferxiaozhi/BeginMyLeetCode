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















