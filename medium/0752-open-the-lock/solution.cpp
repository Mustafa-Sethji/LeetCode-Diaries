class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string start="0000";
        unordered_set<string>st(deadends.begin(),deadends.end());
        queue<pair<string,int>>q;
        unordered_set<string> visited;
        q.push({start,0});
        visited.insert(start);
        while(!q.empty()){
            string password=q.front().first;
            int level=q.front().second;
            q.pop();
            if(password==target)return level;
            for(int i=0;i<4;i++){
                string next = password;

                next[i] = (password[i] - '0' + 1) % 10 + '0';

                if(!st.count(next) && !visited.count(next)){
                    visited.insert(password);
                    q.push({password,level+1});
                }

                next[i] = (password[i] - '0' + 9) % 10 + '0';

                if(!st.count(next) && !visited.count(next)) {
                    visited.insert(next);
                    q.push({next, level + 1});
                }

            }
        }
        return -1; 
    }
};