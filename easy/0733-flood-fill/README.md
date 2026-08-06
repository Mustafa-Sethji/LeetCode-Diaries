# Flood Fill

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:


	Begin with the starting pixel and change its color to color.
	Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
	Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
	The process stops when there are no more adjacent pixels of the original color to update.


Return the modified image after performing the flood fill.

 
Example 1:


Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]

Explanation:



From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.

Note the bottom corner is not colored 2, because it is not horizontally or vertically connected to the starting pixel.


Example 2:


Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0

Output: [[0,0,0],[0,0,0]]

Explanation:

The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.


 
Constraints:


	m == image.length
	n == image[i].length
	1 <= m, n <= 50
	0 <= image[i][j], color < 216
	0 <= sr < m
	0 <= sc < n

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 18.4 MB (beats 30.97%)  
**Submitted:** 2026-08-06T13:14:19.427Z  

```cpp
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int initial=image[sr][sc];
        vector<int>d_row={1,-1,0,0};
        vector<int>d_col={0,0,1,-1};
        image[sr][sc]=color;
        while(!q.empty()){
            int q_size=q.size();
            while(q_size--){
                auto it=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int row=it.first+d_row[i];
                    int col=it.second+d_col[i];
                    if(row<n && row>=0 && col<m && col>=0){
                        if(image[row][col]!=color && image[row][col]==initial){
                            image[row][col]=color;
                            q.push({row,col});
                        }
                    }
                }
            }
        }
        return image;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/flood-fill/)