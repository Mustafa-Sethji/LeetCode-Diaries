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
    long long maxP;
    long long SUM;
    long long solve(TreeNode* root){
        if(!root) return 0;

        long long Lsum=solve(root->left);
        long long Rsum=solve(root->right);
        long long subTreeSum=root->val+Lsum+Rsum;

        long long remaining =SUM-subTreeSum;

        maxP=max(maxP,subTreeSum*remaining);

        return subTreeSum;
    }
    int maxProduct(TreeNode* root) {
        maxP=0;
        SUM=solve(root);//for getting total sum
        maxP=0;
        solve(root);
        
        return maxP % 1000000007;
    }
};