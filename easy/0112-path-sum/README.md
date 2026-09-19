# Path Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the `root` of a binary tree and an integer `targetSum`, return `true` if the tree has a **root-to-leaf** path such that adding up all the values along the path equals `targetSum`.

A **leaf** is a node with no children.

 

**Example 1:**

```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.

```

**Example 2:**

```
Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There are two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.

```

**Example 3:**

```
Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.

```

 

**Constraints:**

- The number of nodes in the tree is in the range [0, 5000].
- -1000 <= Node.val <= 1000
- -1000 <= targetSum <= 1000

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 21.4 MB (beats 66.90%)  
**Submitted:** 2026-09-19T06:57:32.095Z  

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
    bool solve(TreeNode* root,int sum){
        if(root->left==NULL && root->right==NULL && sum+root->val ==target){
            return true;
        }
        if(root->left==NULL && root->right==NULL && sum+root->val !=target){
            return false;
        }

        bool left=false,right=false;
        if(root->left!=NULL)left=solve(root->left,sum+root->val);
        if(root->right!=NULL)right=solve(root->right,sum+root->val);
        return left || right;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        target=targetSum;
        if(root==NULL) return false;
        return solve(root,0);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/path-sum/)