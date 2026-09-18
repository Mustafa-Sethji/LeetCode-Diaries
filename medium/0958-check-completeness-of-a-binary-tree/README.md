# Check Completeness of a Binary Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `root` of a binary tree, determine if it is a *complete binary tree*.

In a **complete binary tree**, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between `1` and `2h` nodes inclusive at the last level `h`.

 

**Example 1:**

```
Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.

```

**Example 2:**

```
Input: root = [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.

```

 

**Constraints:**

- The number of nodes in the tree is in the range [1, 100].
- 1 <= Node.val <= 1000

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 13.5 MB (beats 95.29%)  
**Submitted:** 2026-09-18T11:46:15.132Z  

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
    int count(TreeNode* root){
        if(root==NULL)return 0;
        return 1+count(root->left)+count(root->right);
    }
    bool dfs(TreeNode*root,int i,int n){
        if(root==NULL)return true;
        if(i>n)return false;
        return ( dfs(root->left,2*i,n) && dfs(root->right,2*i+1,n) );
    }
    bool isCompleteTree(TreeNode* root) {
        // queue<TreeNode*>q;
        // if(root==NULL)return true;
        // q.push(root);
        // bool past=false;
        // while(!q.empty()){
        //     TreeNode* node=q.front();
        //     q.pop();
        //     if(node==NULL) past=true;
        //     else{
        //         if(past) return false;
        //         q.push(node->left);
        //         q.push(node->right);
        //     }
        // }
        // return true;

        //dfs
        int total_node=count(root);
        return dfs(root,1,total_node);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/check-completeness-of-a-binary-tree/)