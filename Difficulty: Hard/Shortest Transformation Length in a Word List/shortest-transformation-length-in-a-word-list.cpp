class Solution {
  public:
    int wordLadder(vector<string> &words, string &s, string &e) {
        // code here
        set<string>st(words.begin(),words.end());
        queue<pair<string,int>>q;
        q.push({s,1});
        st.erase(s);
        while(!q.empty()){
            string word=q.front().first;
            int level=q.front().second;
            q.pop();
            
            if(word==e)return level;
            
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;                 
                    if(st.find(word)!=st.end()){
                        q.push({word,level+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};