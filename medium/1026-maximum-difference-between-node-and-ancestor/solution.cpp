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