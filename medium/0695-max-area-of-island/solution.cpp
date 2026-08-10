class Solution {
public:
    int n,m;
    vector<vector<int>>vis;
    vector<int>d_row={-1,1,0,0};
    vector<int>d_col={0,0,1,-1};
    int bfs(int r,int c,vector<vector<int>>&grid){
        queue<pair<int,int>>q;
        q.push({r,c});
        vis[r][c]=1;
        int area=0;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            area++;
            for(int i=0;i<4;i++){
                int n_row=row+d_row[i];
                int n_col=col+d_col[i];
                if(n_row<n && n_row>=0 && n_col<m && n_col>=0 && !vis[n_row][n_col] && grid[n_row][n_col]==1){
                    q.push({n_row,n_col});
                    vis[n_row][n_col]=1;
                }
            }
        }
        return area;

    }
    void dfs_boundry(int r,int c,vector<vector<int>>& grid){
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int n_r=r+d_row[i];
            int n_c=c+d_col[i];
            if(n_r<n && n_r>=0 && n_c<m && n_c>=0 && !vis[n_r][n_c] && grid[n_r][n_c]==1)dfs_boundry(n_r,n_c,grid);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vis.assign(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && !vis[i][j] && grid[i][j]==1) dfs_boundry(i,j,grid);
            }
        }
        int maxi=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(!vis[i][j] && grid[i][j]==1) maxi=max(maxi,bfs(i,j,grid));
            }
        }
        return maxi;
    }
};