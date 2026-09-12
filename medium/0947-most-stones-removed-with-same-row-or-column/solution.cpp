class Solution {
public:
    int n;
    void dfs(int i,vector<vector<int>>& stones,vector<int>&vis){
        vis[i]=1;
        for(int j=0;j<n;j++){
            if( !vis[j] &&
                ( stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1] ) ){
                    dfs(j,stones,vis);
                }
        }
        return ;
    }
    int removeStones(vector<vector<int>>& stones) {
        n=stones.size();
        vector<int>vis(n,0);
        int groups=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                groups++;
                dfs(i,stones,vis);
            }
        }
        return n-groups;
    }
};