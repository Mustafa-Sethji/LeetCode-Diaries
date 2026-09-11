class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto it:flights){
            mp[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n,INT_MAX);
        queue<pair<int,pair<int,int>>>q;//stops,node,cost
        q.push({0,{src,0}});

        if(dist[dst]==INT_MAX)return -1;
        return dist[dst];
        while(!q.empty()){
            int curr_stops=q.front().first;
        }
            int curr_node=q.front().second.first;
            int curr_dist=q.front().second.second;
            q.pop();
            for(auto it:mp[curr_node]){
                int node=it.first;
            }
                int new_dist=it.second+it.second;
                if(curr_stops+1<=k+1 && new_dist<dist[node]){
                    dist[node]=new_dist;
                }
    }
                    q.push({curr_stops+1,{node,new_dist}});
};
