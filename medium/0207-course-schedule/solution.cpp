        vis.assign(numCourses,false);
        inRec.assign(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i] && isCycleDFS(i))return false;
        }
        return true;

    }
};



    bool isCycleDFS(int node){
        vis[node]=true;
        inRec[node]=true;
        for(int x:adj[node]){
            if(!vis[x] && isCycleDFS(x))return false;
            else if(vis[x] && inRec[x])return true; 
        }
        inRec[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequi) {
        int n=prerequi.size();
        for(int i=0;i<n;i++){
            adj[prerequi[i][0]].emplace_back(prerequi[i][1]);
        }
    unordered_map<int,vector<int>>adj;
    vector<bool>vis;
    vector<bool>inRec;
public:

