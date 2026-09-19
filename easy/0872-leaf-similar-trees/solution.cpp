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
    vector<int>arr1;
    vector<int>arr2;

    void dfs1(TreeNode* root){
        if(!root->left && !root->right){
            arr1.push_back(root->val);
            return;
        }
        if(root->left) dfs1(root->left);
        if(root->right) dfs1(root->right);
        return ;
    }

    void dfs2(TreeNode* root){
        if(!root->left && !root->right){
            arr2.push_back(root->val);
            return;
        }
        if(root->left) dfs2(root->left);
        if(root->right) dfs2(root->right);
        return ;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs1(root1);
        dfs2(root2);
        return arr1==arr2;
        
    }
};