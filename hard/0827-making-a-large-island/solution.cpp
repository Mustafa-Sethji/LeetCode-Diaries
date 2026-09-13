class Solution {
public:
    int n;
    vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    int dfs(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&vis,int &label){
        if(i>=n || j>=n || i<0 || j<0 || vis[i][j] || grid[i][j]==0) return 0;
        vis[i][j]=true;
        grid[i][j]=label;
        int siz=1;
        for(auto &dir:directions){
            int nrow=dir[0]+i;
            int ncol=dir[1]+j;
            siz+=dfs(nrow,ncol,grid,vis,label);
        }
        return siz;

    }
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        int maxArea=0;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        unordered_map<int,int>mp;
        int label=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int area=dfs(i,j,grid,visited,label);
                    maxArea=max(maxArea,area);
                    mp[label]=area;
                    label++;
                }
            }
        }
        if(maxArea==0)return 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    vector<int>vis(label,0);
                    int area=1;
                    for(auto &dir:directions){
                        int nrow=dir[0]+i;
                        int ncol=dir[1]+j;
                        if(nrow<0 || ncol<0 || nrow>=n || ncol>=n || grid[nrow][ncol]==0)continue;
                        int labl=grid[nrow][ncol];
                        if( grid[nrow][ncol]!=0 && !vis[labl]){
                            vis[labl]=1;
                            area+=mp[labl];
                        }
                    }
                    maxArea=max(maxArea,area);
                }
            }
        }
        return maxArea;

    }
};