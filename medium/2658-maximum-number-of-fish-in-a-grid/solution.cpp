class Solution {
public:
    int n,m;
    vector<vector<int>>vis;
    vector<int>d_row={-1,1,0,0};
    vector<int>d_col={0,0,1,-1};
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0;
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                queue<pair<pair<int,int>,int>>q;
                vis.assign(n,vector<int>(m,0));
                if(grid[i][j]==0) continue;
                q.push({{i,j},grid[i][j]});
                vis[i][j]=1;
                int fish=0;
                while(!q.empty()){
                    int r=q.front().first.first;
                    int c=q.front().first.second;
                    int fish_in=q.front().second;
                    q.pop();
                    fish+=fish_in;
                    for(int k=0;k<4;k++){
                        int n_r=r+d_row[k];
                        int n_c=c+d_col[k];
                        if(n_r<n && n_r>=0 && n_c>=0 && n_c<m && vis[n_r][n_c]==0 && grid[n_r][n_c]>0){
                            q.push({{n_r,n_c},grid[n_r][n_c]});
                            vis[n_r][n_c]=1;
                        }
                    }
                }
                ans=max(ans,fish);
            }
        }
        return ans;
    }
};