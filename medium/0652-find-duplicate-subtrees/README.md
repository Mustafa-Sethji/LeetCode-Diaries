# Find Duplicate Subtrees

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `root` of a binary tree, return all **duplicate subtrees**.

For each kind of duplicate subtrees, you only need to return the root node of any **one** of them.

Two trees are **duplicate** if they have the **same structure** with the **same node values**.

 

**Example 1:**

```
Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]

```

**Example 2:**

```
Input: root = [2,1,1]
Output: [[1]]

```

**Example 3:**

```
Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]

```

 

**Constraints:**

- The number of the nodes in the tree will be in the range [1, 5000]
- -200 <= Node.val <= 200

## Solution

**Language:** C++  
**Runtime:** 15 ms (beats 83.84%)  
**Memory:** 43.6 MB (beats 53.69%)  
**Submitted:** 2026-09-26T06:21:55.890Z  

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
    string getSubTreeString(TreeNode* root,unordered_map<string,int> &mp,vector<TreeNode*>&res){
        if(!root) return "N";

        string s=to_string(root->val)+","+getSubTreeString(root->left,mp,res)+","+getSubTreeString(root->right,mp,res);

        if(mp[s]==1){
            res.push_back(root);
        }
        mp[s]++;

        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>mp;
        vector<TreeNode*>res;
        getSubTreeString(root,mp,res);

        return res;
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/find-duplicate-subtrees/)