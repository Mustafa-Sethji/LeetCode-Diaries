class Solution {
public:
    unordered_map<int,vector<int>>adj;
    void dfs(int node,vector<int>&vis){
        vis[node]=1;
        for(auto x: adj[node]){
            if(!vis[x])dfs(x,vis);
        }
        return ;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                long long dx=(bombs[i][0]-bombs[j][0]);
                long long dy=(bombs[i][1]-bombs[j][1]);
                long long r=bombs[i][2];
                if(dx*dx+dy*dy<=r*r)adj[i].push_back(j); 
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            dfs(i,vis);
            int count=0;
            for(int i=0;i<n;i++){
                if(vis[i])count++;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};