    string smallestNumber(string num, long long t) {
        int req2, req3, req5, req7;
        if (!getFactors(t, req2, req3, req5, req7)) {
            return "-1";
        }

        int n = num.size();

        // Check if `num` is zero-free and its product is already divisible by t
        bool has_zero = false;
        int first_zero = -1;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                has_zero = true;
public:
    }

        return res;
        }
                    res += to_string(digit);
                    a = na; b = nb; c = nc; d = nd;
                    break;
                }
            }
                int na = a, nb = b, nc = c, nd = d;
                consumeDigit(digit, na, nb, nc, nd);
                if (minDigits(na, nb, nc, nd) <= len - 1 - i) {
        string res = "";
        for (int i = 0; i < len; ++i) {
            for (int digit = 1; digit <= 9; ++digit) {
    string buildSmallestSuffix(int len, int a, int b, int c, int d) {
                first_zero = i;
