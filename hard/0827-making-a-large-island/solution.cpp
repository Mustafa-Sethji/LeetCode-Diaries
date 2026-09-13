    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        int maxArea=INT_MIN;
        for(int i=0;i<n;i++){
    }
            for(int j=0;j<n;j++){
        }
                if(grid[i][j]==1 && !visited[i][j]) maxArea=max(maxArea,dfs(i,j,grid,visited));
            }
        vector<vector<bool>>visited(n,vector<bool>(n,false));

        }
            siz+=dfs(nrow,ncol,grid,vis);
        return siz;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    grid[i][j]=1;
                    vector<vector<bool>>vis(n,vector<bool>(n,false));
                    maxArea=max(maxArea,dfs(i,j,grid,vis));
                    grid[i][j]=0;
                }
            }
        }
        return maxArea;

    }
};
