# Leaf-Similar Trees

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a **leaf value sequence***.*

For example, in the given tree above, the leaf value sequence is `(6, 7, 4, 9, 8)`.

Two binary trees are considered *leaf-similar* if their leaf value sequence is the same.

Return `true` if and only if the two given trees with head nodes `root1` and `root2` are leaf-similar.

 

**Example 1:**

```
Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true

```

**Example 2:**

```
Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false

```

 

**Constraints:**

- The number of nodes in each tree will be in the range [1, 200].
- Both of the given trees will have values in the range [0, 200].

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 15.4 MB (beats 50.49%)  
**Submitted:** 2026-09-19T10:57:19.893Z  

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
    vector<int>arr1;
    vector<int>arr2;

    void dfs1(TreeNode* root){
        if(!root->left && !root->right){
            arr1.push_back(root->val);
            return;
        }
        if(root->left) dfs1(root->left);
        if(root->right) dfs1(root->right);
        return ;
    }

    void dfs2(TreeNode* root){
        if(!root->left && !root->right){
            arr2.push_back(root->val);
            return;
        }
        if(root->left) dfs2(root->left);
        if(root->right) dfs2(root->right);
        return ;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs1(root1);
        dfs2(root2);
        return arr1==arr2;
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/leaf-similar-trees/)