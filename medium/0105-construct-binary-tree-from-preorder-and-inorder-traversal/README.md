# Construct Binary Tree from Preorder and Inorder Traversal

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree and `inorder` is the inorder traversal of the same tree, construct and return *the binary tree*.

 

**Example 1:**

```
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

```

**Example 2:**

```
Input: preorder = [-1], inorder = [-1]
Output: [-1]

```

 

**Constraints:**

- 1 <= preorder.length <= 3000
- inorder.length == preorder.length
- -3000 <= preorder[i], inorder[i] <= 3000
- preorder and inorder consist of unique values.
- Each value of inorder also appears in preorder.
- preorder is guaranteed to be the preorder traversal of the tree.
- inorder is guaranteed to be the inorder traversal of the tree.

## Solution

**Language:** C++  
**Runtime:** 11 ms (beats 17.40%)  
**Memory:** 27.1 MB (beats 90.66%)  
**Submitted:** 2026-09-18T10:08:40.958Z  

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
    // TreeNode* buildTree(vector<int>&preorder,int prestart,int prend,vector<int>&inorder,int instart,int inend,unordered_map<int,int>&inMap){
    //     if(prestart>prend || instart>inend)return NULL;
    //     TreeNode* root=new TreeNode(preorder[prestart]);
    //     int inRoot=inMap[root->val];
    //     int numleft=inRoot-instart;
    //     root->left=buildTree(preorder,prestart+1,prestart+numleft,inorder,instart,inRoot-1,inMap);
    //     root->right=buildTree(preorder,prestart+numleft+1,prend,inorder,inRoot+1,inend,inMap);
    //     return root;

    // }

    TreeNode* solve(vector<int>&preorder,vector<int>&inorder,int start,int end,int &idx){
        if(start>end) return NULL;

        int rootVal=preorder[idx];

        int i;
        for(i=start;i<=end;i++){
            if(inorder[i]==rootVal) break;
        }
        idx++;
        TreeNode* root=new TreeNode(rootVal);
        root->left=solve(preorder,inorder,start,i-1,idx);
        root->right=solve(preorder,inorder,i+1,end,idx);

        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // unordered_map<int,int>inMap;
        // for(int i=0;i<inorder.size();i++)inMap[inorder[i]]=i;
        // TreeNode* root=buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
        // return root;

        int n=inorder.size();
        int idx=0;
        return solve(preorder,inorder,0,n-1,idx);

    }
    
};
```

---

[View on LeetCode](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)