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
    // TreeNode* buildTree(vector<int>&preorder,int prestart,int prend,vector<int>&inorder,int instart,int inend,unordered_map<int,int>&inMap){
    //     if(prestart>prend || instart>inend)return NULL;
    //     TreeNode* root=new TreeNode(preorder[prestart]);
    //     int inRoot=inMap[root->val];
    //     int numleft=inRoot-instart;
    //     root->left=buildTree(preorder,prestart+1,prestart+numleft,inorder,instart,inRoot-1,inMap);
    //     root->right=buildTree(preorder,prestart+numleft+1,prend,inorder,inRoot+1,inend,inMap);
    //     return root;

    // }

    TreeNode* solve(vector<int>&preorder,vector<int>&inorder,int start,int end,int &idx){
        if(start>end) return NULL;

        int rootVal=preorder[idx];

        int i;
        for(i=start;i<=end;i++){
            if(inorder[i]==rootVal) break;
        }
        idx++;
        TreeNode* root=new TreeNode(rootVal);
        root->left=solve(preorder,inorder,start,i-1,idx);
        root->right=solve(preorder,inorder,i+1,end,idx);

        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // unordered_map<int,int>inMap;
        // for(int i=0;i<inorder.size();i++)inMap[inorder[i]]=i;
        // TreeNode* root=buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
        // return root;

        int n=inorder.size();
        int idx=0;
        return solve(preorder,inorder,0,n-1,idx);

    }
    
};