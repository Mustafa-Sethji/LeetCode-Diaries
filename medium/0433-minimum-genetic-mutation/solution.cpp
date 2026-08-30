class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>st(bank.begin(),bank.end());
        queue<pair<string,int>>q;
        q.push({startGene,0});
        if(st.find(startGene)!=st.end())st.erase(startGene);
        while(!q.empty()){
            string word=q.front().first;
            int level=q.front().second;
            q.pop();
            if(word==endGene)return level;
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='A';ch<='Z';ch++){
                    if(ch==original)continue;
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,level+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return -1;
    }
};