class Solution {
public:
    vector<vector<int>>ans;
    int n;
    void solve(int i,vector<int>&temp,int sum,vector<int>&nums){
        if(i>=n )return;
        if(sum==0){
            ans.push_back(temp);
            return;
        }
        if(nums[i]>sum)return;
        else if(nums[i]<=sum){
            temp.emplace_back(nums[i]);
            solve(i,temp,sum-nums[i],nums);
            temp.pop_back();
        }
        solve(i+1,temp,sum,nums);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<int>temp;
        solve(0,temp,target,candidates);
        return ans;
    }
};