class Solution {
public:
    vector<vector<vector<int>>>dp;
    int n;
    int solve_for_alice(int person,int i,int M,vector<int>&piles){
        if(i>=n)return 0;
        if(dp[person][i][M]!=-1)return dp[person][i][M];
        int result;
        if(person==1)result=-1;
        else result=INT_MAX;
        int stones=0;
        for(int x=1;x<=2*M;x++){
            if(i+x-1<n){
                stones+=piles[i+x-1];
                if(person==1){
                    result=max(result,stones+solve_for_alice(0,i+x,max(x,M),piles));
                }
                else{
                    result=min(result,solve_for_alice(1,i+x,max(x,M),piles));
                }
            }
        }
        return dp[person][i][M]=result;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        dp.assign(2,vector<vector<int>>(n,vector<int>(n+1,-1)));
        return solve_for_alice(1,0,1,piles);
    }
};