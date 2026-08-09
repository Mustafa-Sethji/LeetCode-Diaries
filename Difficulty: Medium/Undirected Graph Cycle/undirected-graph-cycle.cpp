class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
           if(vis[i]) continue;
           queue<pair<int,int>>q;
           q.push({i,-1});
           vis[i]=1;
            while(!q.empty()){
                int node=q.front().first;
                int parent=q.front().second;
                q.pop();
                for(int x:adj[node]){
                    if(vis[x]==0){
                        q.push({x,node});
                        vis[x]=1;
                    }
                    else if(vis[x]==1 && parent!=x)return true;
                }
            }
        }
        return false;
    }
};

