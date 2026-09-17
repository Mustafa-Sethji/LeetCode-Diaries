class Solution {
public:
    vector<int>del_row={0,0,1,-1};
    vector<int>del_col={1,-1,0,0};
    int n,m;
    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<int>>&graph){
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int r_=r+del_row[i];
            int c_=c+del_col[i];
            if(r_<n && c_<m && r_>=0 && c_>=0 && !vis[r_][c_] && graph[r_][c_]==0) 
                dfs(r_,c_,vis,graph);
        
        }
        return ;
    }
    int regionsBySlashes(vector<string>& grid) {
        int N=grid.size();
        n=N*3;
        m=N*3;
        vector<vector<int>>graph(n,vector<int>(m,0));
        int k=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]=='\\'){
                    graph[i*3][j*3]=1;
                    graph[i*3+1][j*3+1]=1;
                    graph[i*3+2][j*3+2]=1;
                }
                else if(grid[i][j]=='/'){
                    graph[i*3][j*3+2]=1;
                    graph[i*3+1][j*3+1]=1;
                    graph[i*3+2][j*3]=1;
                }
            }
        }

        vector<vector<int>>vis(n,vector<int>(m,0));

        int region=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && graph[i][j]==0){
                    dfs(i,j,vis,graph);
                    region++;
                }
            }
        }
        return region;
    }
};