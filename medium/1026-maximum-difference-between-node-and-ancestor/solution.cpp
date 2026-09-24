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
    int MAX_DIFF;
    void findMaxDiff(TreeNode* root,TreeNode* child){
        MAX_DIFF=max(MAX_DIFF,abs(root->val - child->val));

        if(child->left)findMaxDiff(root,child->left);
        if(child->right)findMaxDiff(root,child->right);
    }
    void traverse(TreeNode* root){
        
        if(root->left)findMaxDiff(root,root->left);
        if(root->right)findMaxDiff(root,root->right);

        if(root->left)traverse(root->left);
        if(root->right)traverse(root->right);

    }
    int maxAncestorDiff(TreeNode* root) {
        MAX_DIFF=0;
        traverse(root);
        return MAX_DIFF;
    }
};