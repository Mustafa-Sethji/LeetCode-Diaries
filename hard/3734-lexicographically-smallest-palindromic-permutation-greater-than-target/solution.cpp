
            //explore
            if(solve(curr,count,target,i
            +1,isGreater)){ //early 
            return
                return true;
            }

            //undo
            curr.pop_back();
            count[ch-'a']++;
        }
        return false;
    }
    string lexPalindromicPermutation
    (string s, string target) {
        int n=s.size();
        vector<int>count(26,0);
        for(char &ch:s){
            count[ch-'a']++;
        }
        int oddCount=0; //odd frequency 
        wale kitne charcter hai
        for(int c=0;c<26;c++){
            if(count[c]%2==1){
                oddCount++;
                midChar=c+'a';
            }
