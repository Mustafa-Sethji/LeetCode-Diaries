class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>>adjLS(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto &p:pre){
            adjLS[p[1]].emplace_back(p[0]);
            indegree[p[0]]++;
        }
        //for(int i=0;i<indegree.size();i++)cout<<i<<" = "<<indegree[i]<<"\n";
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.emplace_back(node);
            for(auto it:adjLS[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        //for(int p:ans)cout<<p<<" ";
        //cout<<"\n";
        if(ans.size()==numCourses)return ans;
        return {};
    }
};