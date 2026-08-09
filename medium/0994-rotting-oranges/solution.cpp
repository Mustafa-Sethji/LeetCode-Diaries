class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh_orange=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)q.push({i,j});
                else if(grid[i][j]==1)fresh_orange++;
            }
        }
        if(fresh_orange==0)return 0;
        int minutes=0;
        vector<int>d_row={-1,0,1,0};
        vector<int>d_col={0,1,0,-1};
        while(!q.empty() && fresh_orange>0){
            int qsize=q.size();
            while(qsize--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int new_row=r+d_row[i];
                    int new_col=c+d_col[i];
                    if(new_row<n && new_row>-1 && new_col<m && new_col>-1){
                        if(grid[new_row][new_col]==1){
                            fresh_orange--;
                            q.push({new_row,new_col});
                            grid[new_row][new_col]=2;
                        }
                    }
                } 
            }
            minutes++;           
        }

        if(fresh_orange==0)return minutes;
        return -1;
    }
};