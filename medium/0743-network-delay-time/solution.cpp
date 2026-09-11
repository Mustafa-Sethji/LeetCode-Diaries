class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto it:times){
            mp[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,int>>q;
        vector<int>dist(n+1,INT_MAX);
        q.push({k,0});
        while(!q.empty()){
            int node=q.front().first;
            int time=q.front().second;
            q.pop();
            for(auto it:mp[node]){
                int curr=it.first;
                int new_time=time+it.second;
                if(curr<n+1 && dist[curr]>new_time){
                    dist[curr]=new_time;
                    q.push({curr,new_time});
                }
            }
        }
        int mx=*max_element(dist.begin()+1,dist.end());
        if(mx==INT_MAX)return -1;
        return mx;
    }
        dist[k]=0;
};
