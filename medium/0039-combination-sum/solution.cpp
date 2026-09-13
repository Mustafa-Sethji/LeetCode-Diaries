class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return ans;
    vector<vector<int>>ans;
        vector<int>temp;
        solve(0,temp,target,candidates);
    void solve(int i,vector<int>&temp,int sum,vector<int>&nums){
        if(i>=n)return;
    }
    int n;
        n=candidates.size();
        if(sum==0){
            ans.push_back(temp);
        }
            return;
        if(nums[i]>sum)return;
        else{
            temp.emplace_back(nums[i]);
        }
    }
            solve(i,temp,sum-nums[i],nums);
            temp.pop_back();
        return;
};
