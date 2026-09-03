class Solution {
public:
    bool solve(vector<int>&nums,int &op,int mid){
        int k=op;
        for(int x:nums){
            if(x>mid){
                while(x>mid){
                    int p1=x-mid;
                    int p2=mid;
                    x=max(p1,p2);
                    k--;
                    if(k<0) return false;
                }
            }
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int high=*max_element(nums.begin(),nums.end());
        int low=1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(nums,maxOperations,mid)){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;

    }
};
