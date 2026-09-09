# Range Sum Query 2D - Immutable

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a 2D matrix matrix, handle multiple queries of the following type:


	Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).


Implement the NumMatrix class:


	NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
	int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).


You must design an algorithm where sumRegion works on O(1) time complexity.

 
Example 1:

Input
["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
Output
[null, 8, 11, 12]

Explanation
NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)


 
Constraints:


	m == matrix.length
	n == matrix[i].length
	1 <= m, n <= 200
	-104 <= matrix[i][j] <= 104
	0 <= row1 <= row2 < m
	0 <= col1 <= col2 < n
	At most 104 calls will be made to sumRegion.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.8 MB  
**Submitted:** 2026-09-09T18:32:26.735Z  

```cpp
class NumMatrix {
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        prefix.resize(m , vector<int>(n , 0));
        int sum=0;
        for(int c=0;c<n;c++){
            sum+=matrix[0][c];
            prefix[0][c]=sum;
        }
        sum=0;
        for(int r=0;r<m;r++){
            sum+=matrix[r][0];
            prefix[r][0]=sum;
        }
        for (int i = 1; i < m; i++) { //prefix[i][j]=matrix[i][j]+top+left-topleft
            for (int j = 1; j < n; j++) {
                prefix[i][j]=matrix[i][j]+prefix[i][j-1]+prefix[i-1][j]-prefix[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2 ][col2]
             - prefix[row1-1][col2]
             - prefix[row2][col1-1]
             + prefix[row1-1][col1-1];
        int ans=prefix[row2][col2];
        if(row1>0)ans-=prefix[row1-1][col2];
        if(col1>0)ans-=prefix[row2][col1-1];
        if(row1>0 && col1>0)ans+=prefix[row1-1][col2-1];
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/range-sum-query-2d-immutable/)