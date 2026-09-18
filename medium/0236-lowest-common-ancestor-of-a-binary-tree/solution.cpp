/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(root==NULL)return NULL;
        // if(root==p || root==q)return root; 
        // TreeNode* first=lowestCommonAncestor(root->left,p,q);
        // TreeNode* second=lowestCommonAncestor(root->right,p,q);
        // if(first==NULL && second==NULL) return NULL;
        // else if(first==NULL && second!=NULL) return second;
        // else if(first!=NULL && second==NULL) return first;
        // else if(first!=NULL && second!=NULL) return root;
        // else return NULL;

        if(root==NULL) return NULL;

        if(root==p || root==q)return root;

        TreeNode* LeftN=lowestCommonAncestor(root->left,p,q);
        TreeNode* RightN=lowestCommonAncestor(root->right,p,q);

        if(LeftN!=NULL && RightN!=NULL)return root;
        else if(LeftN!=NULL)return LeftN;
        return RightN;
    }
};