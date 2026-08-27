class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        int i = 0;

        while (i < n && freq[target[i] - 'a'] > 0) {
            freq[target[i] - 'a']--;
            i++;
        }

        for (int pos = i; pos >= 0; pos--) {
            if (pos < i) {
                freq[target[pos] - 'a']++;
            }

            if (pos == n) {
                continue;
            }

            int x = target[pos] - 'a';

            for (int j = x + 1; j < 26; j++) {
                if (freq[j] > 0) {
                    string ans;

                    ans += target.substr(0, pos);

                    ans += char('a' + j);
                    freq[j]--;

                    for (int k = 0; k < 26; k++) {
                        ans += string(freq[k], char('a' + k));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};