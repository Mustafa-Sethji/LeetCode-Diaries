class Solution {
  public:
    unordered_map<int,vector<int>>adj;
    vector<int>vis;
    void dfs(int v){
        vis[v]=1;
        for(int u:adj[v]){
            if(vis[u]==0){
                dfs(u);
            }
        }
    }
    int countConnected(int V, vector<vector<int>>& edges) {
        adj.clear();
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vis.assign(V,0);
        int cnt=0;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i);
            }
        }
        return cnt;
    }
};