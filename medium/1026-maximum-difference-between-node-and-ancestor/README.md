# Maximum Difference Between Node and Ancestor

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `root` of a binary tree, find the maximum value `v` for which there exist **different** nodes `a` and `b` where `v = |a.val - b.val|` and `a` is an ancestor of `b`.

A node `a` is an ancestor of `b` if either: any child of `a` is equal to `b` or any child of `a` is an ancestor of `b`.

 

**Example 1:**

```
Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
```

**Example 2:**

```
Input: root = [1,null,2,null,0,3]
Output: 3

```

 

**Constraints:**

- The number of nodes in the tree is in the range [2, 5000].
- 0 <= Node.val <= 105

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 13.8 MB (beats 31.58%)  
**Submitted:** 2026-09-24T11:33:27.516Z  

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int FindMaxDiff(TreeNode* root,int MinV,int MaxV){
        if(root==NULL)return abs(MinV-MaxV);

        MinV=min(MinV,root->val);
        MaxV=max(MaxV,root->val);

        int L=FindMaxDiff(root->left,MinV,MaxV);
        int R=FindMaxDiff(root->right,MinV,MaxV);

        return max(L,R);
    }
    int maxAncestorDiff(TreeNode* root) {
        return FindMaxDiff(root,root->val,root->val);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/)