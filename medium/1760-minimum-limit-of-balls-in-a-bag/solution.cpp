class Solution {
public:
    bool solve(vector<int>&nums,int &op,int mid){
        int k=op;
        for(int &x:nums){
            int nums=x;
            if(x>mid){
                int ops=nums/mid;
                if(nums%mid==0)ops--;
                k-=ops;
                if(k<0)return false;
            }
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int high=*max_element(nums.begin(),nums.end());
        int low=1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(nums,maxOperations,mid)){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;

    }
};