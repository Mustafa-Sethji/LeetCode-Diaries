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
    int count_good(TreeNode*root,int maxi){
        if(root==NULL) return 0;

        int l=0,r=0,curr=0;
        if(root->val>=maxi){
            curr=1;
            maxi=root->val;
        }
        if(root->left)l+=count_good(root->left,maxi);
        if(root->right)r+=count_good(root->right,maxi);

        return l+r+curr;
    }
    int goodNodes(TreeNode* root) {
        return count_good(root,root->val);
    }
};