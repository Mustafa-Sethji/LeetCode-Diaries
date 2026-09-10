class Solution {
public:
    int n;
    vector<int>delrow={1,0,0,-1};
    vector<int>delcol={0,1,-1,0};
    bool dfs(vector<vector<int>>&grid,int time,int row,int col,vector<vector<int>>&vis){
        vis[row][col]=1;
        if(row==n-1 && col==n-1)return true;
        
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow<n && ncol<n && nrow>=0 && ncol>=0 && !vis[nrow][ncol] && grid[nrow][ncol]<=time){
                if(dfs(grid,time,nrow,ncol,vis)) return true;
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        int low=0,high=n*n-1;
        int mid=0;
        while(low<=high){
            mid=low+(high-low)/2;
            vector<vector<int>>vis(n,vector<int>(n,0));
            if(dfs(grid,mid,0,0,vis))high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};