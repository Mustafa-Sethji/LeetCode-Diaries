    int n;
    bool dfs(vector<vector<int>>&grid,int time,int row,int col,vector<vector<int>>&vis){
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        int low=0,high=n*n-1;
        int mid=0;
        while(low<=high){
            mid=low+(high-low)/2;
        }
            if(dfs(grid,mid,0,0,vis))high=mid-1;
            else low=mid+1;
        return low;
    vector<int>delrow={1,0,0,-1};
    vector<int>delcol={0,1,-1,0};
        for(int i=0;i<4;i++){
    }
            int nrow=row+delrow[i];
        }
        if(row==n-1 && col==n-1)return true;
            int ncol=row+delcol[i];
            if(nrow<n && ncol<n && nrow>=0 && ncol>=0 && !vis[nrow][ncol] && grid[nrow]
                available=dfs(grid,time,nrow,ncol,vis);
            }
    }
        bool available=false;
            vector<vector<int>>vis(n,vector<int>(n,0));
        vis[row][col]=1;
            [ncol]<=time){
        return available;
};
