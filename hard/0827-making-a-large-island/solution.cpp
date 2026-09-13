class Solution {
public:
    int n;
    vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    int dfs(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&vis){
        if(i>=n || j>=n || i<0 || j<0 || vis[i][j] || grid[i][j]==0) return 0;
        vis[i][j]=true;
        int siz=1;
        for(auto &dir:directions){
            int nrow=dir[0]+i;
            int ncol=dir[1]+j;
            siz+=dfs(nrow,ncol,grid,vis);
        }
        return siz;

    }
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        int maxArea=INT_MIN;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]) maxArea=max(maxArea,dfs(i,j,grid,visited));
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    grid[i][j]=1;
                    vector<vector<bool>>vis(n,vector<bool>(n,false));
                    maxArea=max(maxArea,dfs(i,j,grid,vis));
                    grid[i][j]=0;
                }
            }
        }
        return maxArea;

    }
};