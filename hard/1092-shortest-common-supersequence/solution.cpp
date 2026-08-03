    vector<vector<bool>> vis;
    string solve(string &s1,string &s2,int i,int j){
        if(i==s1.size() || j==s2.size())return s1.substr(i)+s2.substr(j);

        if(vis[i][j])return dp[i][j];

        vis[i][j]=true;

        if(s1[i]==s2[j]){
            return dp[i][j]=string(1, s1[i])+solve(s1,s2,i+1,j+1);
        }
        else {
            string first=string(1,s1[i])+solve(s1,s2,i+1,j);
            string second=string(1,s2[j])+solve(s1,s2,i,j+1);
            if(first.size()<second.size())return dp[i][j]=first;
            else return dp[i][j]=second;
        }
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vis.assign(n,vector<bool>(m,false));
        dp.assign(n,vector<string>(m,"#"));

        return solve(str1,str2,0,0);
    }

};
    vector<vector<string>>dp;
public:
class Solution {
