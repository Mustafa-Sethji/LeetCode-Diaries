class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for (int x = nums[i] + 1; x < nums[i + 1]; x++) {
        }
        vector<int>ans;
        return ans;
                ans.push_back(x);
            }
    }
};
