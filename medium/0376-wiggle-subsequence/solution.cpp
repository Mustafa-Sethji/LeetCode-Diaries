class Solution {
public:
    vector<vector<int>>dp;
    int n;
    vector<int>arr;
    int solve(int i,int prev){
        if(i>=n)return 0;

        if(dp[i][prev+1]!=-1)return dp[i][prev+1];

        int not_take=0+solve(i+1,prev);

        int take=0;

        if(prev == -1) {
            if(arr[i] != 0)
                take = 1 + solve(i + 1, i);
        }
        else if(arr[prev]>0 && arr[i]<0)take=1+solve(i+1,i);
        else if(arr[prev]<0 && arr[i]>0)take=1+solve(i+1,i);

        return dp[i][prev+1]=max(take,not_take);

    }
    int wiggleMaxLength(vector<int>& nums) {
        arr.clear();

        if(nums.size()<=1)return nums.size();

        for(int i=0;i<nums.size()-1;i++){
            arr.push_back(nums[i+1]-nums[i]);
        }

        n=arr.size();
        // if(n<=1)return n+1; 

        dp.assign(n+1,vector<int>(n+1,-1));

        return solve(0,-1)+1;
    }
};