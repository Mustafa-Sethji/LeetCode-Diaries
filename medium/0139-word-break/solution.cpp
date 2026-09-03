class Solution {
public:
    int t[301];
    bool solve(string s,int idx,unordered_set<string>& dict,int n){
        if(idx==n){
            return true;
        }

        if(t[idx]!=-1) return t[idx];

        if(dict.find(s)!=dict.end()){
            return true;
        }
        for(int l=1;idx+l<=n;l++){
            string temp=s.substr(idx,l);
            if(dict.find(temp)!=dict.end() && solve(s,idx+l,dict,n)) return t[idx]=true;
        }
        return t[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(t,-1,sizeof(t));
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return solve(s,0,dict,s.size());
    }
};