class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        unordered_map<char,vector<char>>map;
        unordered_map<char,int>indegree;
        
        int n=words.size();
        
        for(string word : words){
            for(char ch : word){
                indegree[ch] = 0;
            }
        }
        
        for(int i=0;i<n-1;i++){
            string word1=words[i];
            string word2=words[i+1];
            int k=0;
            while(k<word1.size() && k<word2.size()){
                if(word1[k]==word2[k])k++;
                else if(word1[k]!=word2[k]){
                    map[word1[k]].push_back(word2[k]);
                    indegree[word2[k]]++;
                    break;
                }
            }
        }
        queue<char>q;
        for(auto &[ch, deg] : indegree) {
            if(deg == 0) {
                q.push(ch);
            }
        }
        string ans="";
        while(!q.empty()){
            char u=q.front();
            q.pop();
            ans+=u;
            for(char v:map[u]){
                indegree[v]--;
                if(indegree[v]==0)q.push(v);
            }
        }
        
        if(ans.size() != indegree.size()) {
            return "";
        }

        return ans;
    }
};