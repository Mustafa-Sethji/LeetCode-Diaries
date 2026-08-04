class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            int curr=nums[i];
        }
        vector<int>ans;
        return ans;
            if(curr+1!=nums[i+1]){
                ans.push_back(curr+1);
            }
    }
};
