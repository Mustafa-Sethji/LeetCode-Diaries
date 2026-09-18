# Binary Tree Right Side View

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `root` of a binary tree, imagine yourself standing on the **right side** of it, return *the values of the nodes you can see ordered from top to bottom*.

 

**Example 1:**

**Input:** root = [1,2,3,null,5,null,4]

**Output:** [1,3,4]

**Explanation:**

**Example 2:**

**Input:** root = [1,2,3,4,null,null,null,5]

**Output:** [1,3,4,5]

**Explanation:**

**Example 3:**

**Input:** root = [1,null,3]

**Output:** [1,3]

**Example 4:**

**Input:** root = []

**Output:** []

 

**Constraints:**

- The number of nodes in the tree is in the range [0, 100].
- -100 <= Node.val <= 100

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 15.3 MB (beats 13.63%)  
**Submitted:** 2026-09-18T09:20:16.028Z  

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
    int max_lvl=0;
    void traverse_right_boundry(TreeNode*root,vector<int> &ans,int level){
        if(root==NULL)return;
        if(level>max_lvl){
            max_lvl=level;
            ans.emplace_back(root->val);
        }
        if(root->right)traverse_right_boundry(root->right,ans,level+1);
        if(root->left)traverse_right_boundry(root->left,ans,level+1);
        return;
    }
    void traverse_left_inner_boundry(TreeNode*root,vector<int>&ans,int curr_lvl){
        if(root==NULL) return;
        if(curr_lvl>max_lvl){
            max_lvl=curr_lvl;
            ans.emplace_back(root->val);
        }
        if(root->right)traverse_left_inner_boundry(root->right,ans,curr_lvl+1);
        if(root->left)traverse_left_inner_boundry(root->left,ans,curr_lvl+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        // vector<int>ans;
        // if(root==NULL)return ans;
        // int level=1;
        // ans.emplace_back(root->val);
        // traverse_right_boundry(root->right,ans,1);
        // traverse_left_inner_boundry(root->left,ans,1);
        // return ans;

        // level order traversal;

        if(root==NULL)return {};
        queue<TreeNode*>q;
        vector<int>ans;
        q.push(root);
        TreeNode* Node;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                Node=q.front();
                q.pop();
                if(Node->left!=NULL)q.push(Node->left);
                if(Node->right!=NULL)q.push(Node->right);
            }
            ans.push_back(Node->val);
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/binary-tree-right-side-view/)