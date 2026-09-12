class Solution {
public:
    int n;
    int removeStones(vector<vector<int>>& stones) {
        n=stones.size();
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
        }
                groups++;
            }
        int groups=0;
                dfs(i,stones,vis);
    void dfs(int i,vector<vector<int>>& stones,vector<int>&vis){
        vis[i]=1;
    }
        for(int j=0;j<n;j++){
            if( !vis[j] &&
        }
                ( stones[i][0]==stones[j][0] || stones[j][1]==stones[j][1] ) ){
                    dfs(j,stones,vis);
                }
    }
        return ;
        return n-groups;
};
