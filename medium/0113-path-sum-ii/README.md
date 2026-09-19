# Path Sum II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `root` of a binary tree and an integer `targetSum`, return *all **root-to-leaf** paths where the sum of the node values in the path equals *`targetSum`*. Each path should be returned as a list of the node **values**, not node references*.

A **root-to-leaf** path is a path starting from the root and ending at any leaf node. A **leaf** is a node with no children.

 

**Example 1:**

```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

```

**Example 2:**

```
Input: root = [1,2,3], targetSum = 5
Output: []

```

**Example 3:**

```
Input: root = [1,2], targetSum = 0
Output: []

```

 

**Constraints:**

- The number of nodes in the tree is in the range [0, 5000].
- -1000 <= Node.val <= 1000
- -1000 <= targetSum <= 1000

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 21 MB (beats 39.79%)  
**Submitted:** 2026-09-19T06:43:45.099Z  

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
    int target;
    vector<vector<int>>ans;
    void solve(TreeNode* root,vector<int>&arr,int sum){
        if(root->left==NULL && root->right==NULL && sum+root->val ==target){
            arr.push_back(root->val);
            ans.push_back(arr);
            arr.pop_back();
            return;
        }

        arr.push_back(root->val);
        if(root->left!=NULL)solve(root->left,arr,sum+root->val);
        if(root->right!=NULL)solve(root->right,arr,sum+root->val);
        arr.pop_back();
        return;


    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target=targetSum;
        vector<int>arr;
        if(root==NULL) return {};
        solve(root,arr,0);
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/path-sum-ii/)