# Image Overlap

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given two images, img1 and img2, represented as binary, square matrices of size n x n. A binary matrix has only 0s and 1s as values.

We translate one image however we choose by sliding all the 1 bits left, right, up, and/or down any number of units. We then place it on top of the other image. We can then calculate the overlap by counting the number of positions that have a 1 in both images.

Note also that a translation does not include any kind of rotation. Any 1 bits that are translated outside of the matrix borders are erased.

Return the largest possible overlap.

 
Example 1:

Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
Output: 3
Explanation: We translate img1 to right by 1 unit and down by 1 unit.

The number of positions that have a 1 in both images is 3 (shown in red).



Example 2:

Input: img1 = [[1]], img2 = [[1]]
Output: 1


Example 3:

Input: img1 = [[0]], img2 = [[0]]
Output: 0


 
Constraints:


	n == img1.length == img1[i].length
	n == img2.length == img2[i].length
	1 <= n <= 30
	img1[i][j] is either 0 or 1.
	img2[i][j] is either 0 or 1.

## Solution

**Language:** C++  
**Runtime:** 44 ms (beats 74.22%)  
**Memory:** 13.1 MB (beats 55.83%)  
**Submitted:** 2026-09-13T06:02:58.626Z  

```cpp
class Solution {
public:
    int n;
    int counting(vector<vector<int>>& img1, vector<vector<int>>& img2,int &row_offset,int &col_offset){
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int i_b=i+row_offset;
                int j_b=j+col_offset;
                if(i_b<0 || i_b>=n || j_b<0 || j_b>=n) continue;
                if(img1[i][j]==1 && img2[i_b][j_b]==1)cnt++;
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        n=img1.size();
        int maxCount=0;
        for(int row_offset=-n+1;row_offset<=n-1;row_offset++){
            for(int col_offset=-n+1;col_offset<=n-1;col_offset++){
                maxCount=max(maxCount,counting(img1,img2,row_offset,col_offset));
            }
        }
        return maxCount;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/image-overlap/)