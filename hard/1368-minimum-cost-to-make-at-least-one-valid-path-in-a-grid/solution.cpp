class Solution {
public:
    vector<vector<int>>del={{0,1},{0,-1},{1,0},{-1,0}};
    int m,n;
    int dfs(int row,int col,vector<vector<int>>&grid,vector<vector<bool>>&vis,int cost){
        if(row==m-1 && col==n-1)return cost;
        vis[row][col]=true;
        int min_cost=INT_MAX;
        //now explore
        for(int i=0;i<4;i++){
            int nrow=row+del[i][0];
            int ncol=col+del[i][1];
            if(nrow<m && nrow>=0 && ncol<n && ncol>=0 && !vis[nrow][ncol]){
                int nexcost=cost+ ((grid[row][col]-1!=i) ? 1:0 );
                min_cost=min(min_cost,dfs(nrow,ncol,grid,vis,nexcost));
            }
        }

        vis[row][col]=false;
        return min_cost;

    }
    int minCost(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        return dfs(0,0,grid,vis,0); //explore all paths by backtracking

    }
};