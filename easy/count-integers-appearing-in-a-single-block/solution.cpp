class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int prev=-1;
        int n=nums.size();
        int ans=0;
        if(n==1) return 0;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                if(prev==-1 || nums[i]!=prev){
                    ans++;
                    prev=nums[i];
                }
            }
        }
        return ans;
    }
};