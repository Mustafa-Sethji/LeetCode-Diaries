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