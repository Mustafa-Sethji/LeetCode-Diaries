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
    int max_lvl=0;
    void traverse_right_boundry(TreeNode*root,vector<int> &ans,int level){
        if(root==NULL)return;
        if(level>max_lvl){
            max_lvl=level;
            ans.emplace_back(root->val);
        }
        if(root->right)traverse_right_boundry(root->right,ans,level+1);
        if(root->left)traverse_right_boundry(root->left,ans,level+1);
        return;
    }
    void traverse_left_inner_boundry(TreeNode*root,vector<int>&ans,int curr_lvl){
        if(root==NULL) return;
        if(curr_lvl>max_lvl){
            max_lvl=curr_lvl;
            ans.emplace_back(root->val);
        }
        if(root->right)traverse_left_inner_boundry(root->right,ans,curr_lvl+1);
        if(root->left)traverse_left_inner_boundry(root->left,ans,curr_lvl+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        // vector<int>ans;
        // if(root==NULL)return ans;
        // int level=1;
        // ans.emplace_back(root->val);
        // traverse_right_boundry(root->right,ans,1);
        // traverse_left_inner_boundry(root->left,ans,1);
        // return ans;

        // level order traversal;

        if(root==NULL)return {};
        queue<TreeNode*>q;
        vector<int>ans;
        q.push(root);
        TreeNode* Node;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                Node=q.front();
                q.pop();
                if(Node->left!=NULL)q.push(Node->left);
                if(Node->right!=NULL)q.push(Node->right);
            }
            ans.push_back(Node->val);
        }
        return ans;
    }
};