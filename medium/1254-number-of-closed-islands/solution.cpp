class Solution {
public:
    int n,m;

    bool dfs(int r,int c,vector<vector<int>>&vis,vector<vector<int>>&grid){

        if( r>=n || r<0 || c<0 || c>=m )return false;

        if(grid[r][c]==1)
            return true;
        if(vis[r][c])
            return true;

        vis[r][c]=1;

        bool left_bound=dfs(r,c-1,vis,grid);
        bool right_bound=dfs(r,c+1,vis,grid);
        bool up_bound=dfs(r-1,c,vis,grid);
        bool down_bound=dfs(r+1,c,vis,grid);

        return (left_bound && right_bound && up_bound && down_bound); 
    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int region=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==0 && !vis[i][j]  && dfs(i,j,vis,grid) )region++;
            }
        }
        return region;
    }
};