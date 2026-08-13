class Solution {
public:
    struct Node {
        int len;       // length of segment
        int pref;      // longest same-character prefix
        int suff;      // longest same-character suffix
        int best;      // longest same-character substring
        char leftChar;
        char rightChar;

        Node() {
            len = pref = suff = best = 0;
            leftChar = rightChar = '#';
        }

        Node(char c) {
            len = pref = suff = best = 1;
            leftChar = rightChar = c;
        }
    };

    vector<Node> seg;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.pref = a.pref;
        res.suff = b.suff;

        // If the whole left segment has the same character
        // as the beginning of the right segment
        if (a.pref == a.len && a.rightChar == b.leftChar)
            res.pref = a.len + b.pref;

        // If the whole right segment has the same character
        // as the end of the left segment
        if (b.suff == b.len && a.rightChar == b.leftChar)
            res.suff = b.len + a.suff;

        res.best = max(a.best, b.best);

        // Join suffix of left + prefix of right
        if (a.rightChar == b.leftChar)
            res.best = max(res.best, a.suff + b.pref);

        return res;
    }

    void build(int node, int l, int r, string &s) {
        if (l == r) {
            seg[node] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid, s);
        build(2 * node + 1, mid + 1, r, s);

        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            seg[node] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx, c);
        else
            update(2 * node + 1, mid + 1, r, idx, c);

        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        int n = s.size();

        seg.resize(4 * n + 5);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, idx, c);

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};