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