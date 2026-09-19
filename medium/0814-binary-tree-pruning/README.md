# Binary Tree Pruning

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `root` of a binary tree, return *the same tree where every subtree (of the given tree) not containing a *`1`* has been removed*.

A subtree of a node `node` is `node` plus every node that is a descendant of `node`.

 

**Example 1:**

```
Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.

```

**Example 2:**

```
Input: root = [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]

```

**Example 3:**

```
Input: root = [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]

```

 

**Constraints:**

- The number of nodes in the tree is in the range [1, 200].
- Node.val is either 0 or 1.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 12.5 MB (beats 76.47%)  
**Submitted:** 2026-09-19T06:09:41.835Z  

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
    int helper(TreeNode * root){
        if(root==NULL) return 0;

        int Left_one=-1,Right_one=-1;
        if(root->left!=NULL) Left_one=helper(root->left);
        if(root->right!=NULL) Right_one=helper(root->right);

        if(Left_one==0)root->left=NULL;
        if(Right_one==0)root->right=NULL;

        if(root->val==1 && Left_one>=0 && Right_one>=0)return 1+Left_one+Right_one;
        if(root->val==1 && Left_one>=0)return 1+Left_one;
        if(root->val==1 && Right_one>=0)return 1+Right_one;
        if(root->val==1) return 1;
        if(root->val==0 && Left_one>=0 && Right_one>=0)return Left_one+Right_one;
        if(root->val==0 && Left_one>=0)return Left_one;
        if(root->val==0 && Right_one>=0)return Right_one;
        return 0;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root->val==0 && root->right==NULL && root->left==NULL)return NULL;
        helper(root);
        if(root->val==0 && root->right==NULL && root->left==NULL)return NULL;
        return root;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/binary-tree-pruning/)