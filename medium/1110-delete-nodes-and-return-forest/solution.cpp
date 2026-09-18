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
    vector<TreeNode*>result;
    TreeNode* helper(TreeNode* root,unordered_set<int>&st){
        if(root==NULL)return NULL;

        root->left=helper(root->left,st);
        root->right=helper(root->right,st);

        if(st.count(root->val)){
            if(root->left!=NULL)result.push_back(root->left);
            if(root->right!=NULL)result.push_back(root->right);
            return NULL;
        }
        else return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>st;
        for(int &x:to_delete)st.insert(x);

        // func
        helper(root,st);

        if(!st.count(root->val)) result.push_back(root);

        return result;
    }
};