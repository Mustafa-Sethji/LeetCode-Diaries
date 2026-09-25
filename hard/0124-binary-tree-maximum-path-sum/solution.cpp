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
    // vector<int>maxi_sum;
    // int maxi=INT_MIN;
    // int single_maxi=INT_MIN;
    // int func(TreeNode* root){
    //     if(root==NULL)return 0;
    //     if(root->left==NULL && root->right==NULL) {
    //         maxi=max(root->val,maxi);
    //         return root->val;
    //     }
    //     int lh=func(root->left);
    //     int rh=func(root->right);
    //     maxi=max(maxi,max(root->val+lh,max(root->val+rh,root->val)));
    //     if(root->left!=NULL && root->right!=NULL)single_maxi=max(single_maxi,root->val+lh+rh);
    //     int mossi=max(root->val+lh,max(root->val+rh,root->val));
    //     return mossi;
    // }

    int maxi=INT_MIN;
    int solve(TreeNode* root){
        if(!root)return 0;

        int L=max(0,solve(root->left));
        int R=max(0,solve(root->right));

        //path passing thorugh current node
        int through_node=root->val+L+R;

        //update global maximum
        maxi=max(maxi,through_node);

        // Return only one side to parent
        return root->val+max(L,R);
    }
    int maxPathSum(TreeNode* root) {
        int returned_max=solve(root);
        return max(returned_max,maxi);
    }
};



//CLASSICAL CODE
// class Solution {
// public:
//     int func(TreeNode* root,int &maxi){
//         if(root==NULL)return 0;
//         int lh=max(0,func(root->left,maxi));
//         int rh=max(0,func(root->right,maxi));
//         maxi=max(maxi,root->val+lh+rh);
//         return root->val+max(lh,rh);
//     }
//     int maxPathSum(TreeNode* root) {
//         int maxi=INT_MIN;
//         func(root,maxi);
//         return maxi;
//     }
// };