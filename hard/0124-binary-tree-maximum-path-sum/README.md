# Binary Tree Maximum Path Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

A **path** in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence **at most once**. Note that the path does not need to pass through the root.

The **path sum** of a path is the sum of the node's values in the path.

Given the `root` of a binary tree, return *the maximum **path sum** of any **non-empty** path*.

 

**Example 1:**

```
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

```

**Example 2:**

```
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

```

 

**Constraints:**

- The number of nodes in the tree is in the range [1, 3 * 104].
- -1000 <= Node.val <= 1000

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 27.9 MB (beats 77.29%)  
**Submitted:** 2026-09-25T10:22:24.511Z  

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
    vector<int>maxi_sum;
    int maxi=INT_MIN;
    int single_maxi=INT_MIN;
    int func(TreeNode* root){
        if(root==NULL)return 0;
        if(root->left==NULL && root->right==NULL) {
            maxi=max(root->val,maxi);
            return root->val;
        }
        int lh=func(root->left);
        int rh=func(root->right);
        maxi=max(maxi,max(root->val+lh,max(root->val+rh,root->val)));
        if(root->left!=NULL && root->right!=NULL)single_maxi=max(single_maxi,root->val+lh+rh);
        int mossi=max(root->val+lh,max(root->val+rh,root->val));
        return mossi;
    }
    int maxPathSum(TreeNode* root) {
        int h=func(root);
        maxi=max(single_maxi,maxi);
        return max(maxi,h);
    }
};



//CLASSICAL CODE
// class Solution {
// public:
//     int func(TreeNode* root,int &maxi){
//         if(root==NULL)return 0;
//         int lh=max(0,func(root->left,maxi));
//         int rh=max(0,func(root->right,maxi));
//         maxi=max(maxi,root->val+lh+rh);
//         return root->val+max(lh,rh);
//     }
//     int maxPathSum(TreeNode* root) {
//         int maxi=INT_MIN;
//         func(root,maxi);
//         return maxi;
//     }
// };
```

---

[View on LeetCode](https://leetcode.com/problems/binary-tree-maximum-path-sum/)