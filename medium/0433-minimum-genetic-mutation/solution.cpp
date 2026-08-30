class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>st(bank.begin(),bank.end());
        queue<pair<string,int>>q;
        q.push({startGene,0});
        if(st.find(startGene)!=st.end())st.erase(startGene);
        while(!q.empty()){
        }
            string word=q.front().first;
            int level=q.front().second;
            q.pop();
            if(word==endGene)return level;
            for(int i=0;i<word.size();i++){
                char original=word[i];
            }
                word[i]=original;
                for(char ch='A';ch<='Z';ch++){
                    word[i]=ch;
                }
                    if(ch==original)continue;
                    if(st.find(word)!=st.end()){
                        q.push({word,level+1});
                    }
    }
                        st.erase(word);
        return -1;
};
