        }
        for(int i=0;i<n;i++) dist[i][i]=0;
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
        }

                for(int j=0;j<n;j++){
            }
                    if( dist[i][via]!=INT_MAX && 
                }
                        dist[via][j]!=INT_MAX &&
                        dist[i][via]+dist[via][j]<dist[i][j] ){
                        dist[i][j]=dist[i][via]+dist[via][j];

                    }

        pair<int,int>ans={-1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j]<=dt)rechable+=1;
            }
            int rechable=0;
            if(i==0)ans={i,rechable};
            else{
                if(rechable<ans.second)ans={i,rechable};
            dist[it[1]][it[0]]=it[2];
            dist[it[0]][it[1]]=it[2];
        for(auto it:edges){
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
    int findTheCity(int n, vector<vector<int>>& edges, int dt){
public:
class Solution {
