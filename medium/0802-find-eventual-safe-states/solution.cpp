class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //reverse adjlist
        unordered_map<int,vector<int>>map;
        vector<int>indegree(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(auto &x:graph[i]){
                map[x].emplace_back(i);
                indegree[i]++;
            }
        }
        int n=graph.size();
        queue<int>q;
        for(int i=0;i<n;i++) if(indegree[i]==0)q.push(i);
        vector<int>ans;
        while(!q.empty()){
            int v=q.front();
            q.pop();
            ans.emplace_back(v);
            for(auto &it:map[v]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};