class Solution {
public:
    int n;
    int m;
    vector<int>vis;
    void dfs(unordered_map<int,vector<int>>&graph,int node,unordered_map<int,int> &freq,vector<int> &indices,vector<int>&source){
        vis[node]=m;
        freq[source[node]]++;
        indices.push_back(node);
        for(int &v:graph[node]){
            if(!vis[v]) dfs(graph,v,freq,indices,source);
        }
        return;
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        n=source.size();
        m=1;
        unordered_map<int,vector<int>>graph;
        for(auto &v:allowedSwaps){
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }

        vis.assign(n,0);
        int hamming=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>freq;
            vector<int>indices;
            if(!vis[i])dfs(graph,i,freq,indices,source);
            else continue;

            for(int k=0;k<indices.size();k++){
                if(vis[indices[k]]!=m)continue;
                if(freq.find(target[indices[k]])!=freq.end() && freq[target[indices[k]]]>=1){
                    freq[target[indices[k]]]--;
                    hamming++;
                }
            }
            m++;

        }
        return n-hamming;
    }
};