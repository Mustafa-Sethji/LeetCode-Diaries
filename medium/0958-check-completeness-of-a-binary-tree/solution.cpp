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
    int count(TreeNode* root){
        if(root==NULL)return 0;
        return 1+count(root->left)+count(root->right);
    }
    bool dfs(TreeNode*root,int i,int n){
        if(root==NULL)return true;
        return ( dfs(root->left,2*i,n) && dfs(root->right,2*i+1,n) );
    }
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        if(root==NULL)return true;
        q.push(root);
        bool past=false;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL) past=true;
            else{
                if(past) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;

        //dfs
        // int total_node=count(root);
        // return dfs(root,1,total_node);
    }
};