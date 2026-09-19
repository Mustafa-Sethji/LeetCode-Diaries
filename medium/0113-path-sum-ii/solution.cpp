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
    vector<vector<int>>ans;
    void solve(TreeNode* root,vector<int>&arr,int sum){
        if(root->left==NULL && root->right==NULL && sum+root->val ==target){
            arr.push_back(root->val);
            ans.push_back(arr);
            arr.pop_back();
            return;
        }

        arr.push_back(root->val);
        if(root->left!=NULL)solve(root->left,arr,sum+root->val);
        if(root->right!=NULL)solve(root->right,arr,sum+root->val);
        arr.pop_back();
        return;


    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target=targetSum;
        vector<int>arr;
        if(root==NULL) return {};
        solve(root,arr,0);
        return ans;
    }
};