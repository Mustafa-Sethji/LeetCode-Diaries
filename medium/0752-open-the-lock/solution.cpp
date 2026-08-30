class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st(wordList.begin(),wordList.end());
        queue<vector<string>>q;
        q.push({beginWord});
        vector<vector<string>>ans;
        bool found=false;
        while(!q.empty() && !found){
            int size=q.size();
            set<string>used;
            while(size--){
                vector<string> temp=q.front();
                string word=temp.back();
                q.pop();
                for(int i=0;i<word.size();i++){
                    char original=word[i];
                    for(char ch='a';ch<='z';ch++){
                        if(original==ch)continue;
                        word[i]=ch;

                        if(st.find(word)!=st.end()){
                            temp.push_back(word);

                            if(word==endWord){
                                ans.push_back(temp);
                                found=true;
                            }
                            else {q.push(temp);}
                            
                            used.insert(word);
                            temp.pop_back();
                        }
                    }
                    word[i]=original;
                }
            }
            for(string x:used) st.erase(x);
        }
        return ans;
    }
};