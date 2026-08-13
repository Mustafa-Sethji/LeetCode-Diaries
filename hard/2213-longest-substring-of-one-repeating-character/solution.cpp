        res.rightChar = b.rightChar;
        res.leftChar = a.leftChar;

        Node res;
        res.len = a.len + b.len;
        if (b.len == 0) return a;

    vector<Node> seg;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        }

        Node(char c) {
            len = pref = suff = best = 1;
            leftChar = rightChar = c;
        }
    };

        int suff;      // longest same-character suffix
        int best;      // longest same-character substring
        char leftChar;
        char rightChar;

        Node() {
            len = pref = suff = best = 0;
            leftChar = rightChar = '#';
class Solution {
public:
    struct Node {
        int len;       // length of segment
        int pref;      // longest same-character prefix
