class NumMatrix {
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        prefix.resize(m , vector<int>(n , 0));
        int sum=0;
        for(int c=0;c<n;c++){
            sum+=matrix[0][c];
            prefix[0][c]=sum;
        }
        sum=0;
        for(int r=0;r<m;r++){
            sum+=matrix[r][0];
            prefix[r][0]=sum;
        }
        for (int i = 1; i < m; i++) { //prefix[i][j]=matrix[i][j]+top+left-topleft
            for (int j = 1; j < n; j++) {
                prefix[i][j]=matrix[i][j]+prefix[i][j-1]+prefix[i-1][j]-prefix[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2 ][col2]
             - prefix[row1-1][col2]
             - prefix[row2][col1-1]
             + prefix[row1-1][col1-1];
        int ans=prefix[row2][col2];
        if(row1>0)ans-=prefix[row1-1][col2];
        if(col1>0)ans-=prefix[row2][col1-1];
        if(row1>0 && col1>0)ans+=prefix[row1-1][col2-1];
        return ans;
    }
};