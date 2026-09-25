class Solution {
public:
    set<string> parse(string &s, int &i) {
        set<string> result;
        vector<string> current = {""};

        while (i < s.size() && s[i] != '}') {
            
            if (s[i] == '{') {
                i++; // skip '{'
                set<string> inside = parse(s, i);
                i++; // skip '}'

                vector<string> temp;

                for (string a : current) {
                    for (string b : inside) {
                        temp.push_back(a + b);
                    }
                }

                current = temp;
            }
            
            else if (s[i] == ',') {
                // Union current results into result
                for (string x : current)
                    result.insert(x);

                current = {""};
                i++;
            }
            
            else {
                // Normal character
                char ch = s[i];
                for (string &x : current)
                    x += ch;

                i++;
            }
        }

        // Add remaining concatenated strings
        for (string x : current)
            result.insert(x);

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ansSet = parse(expression, i);

        return vector<string>(ansSet.begin(), ansSet.end());
    }
};