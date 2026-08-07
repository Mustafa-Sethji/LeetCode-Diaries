# Smallest Divisible Digit Product II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a string num which represents a positive integer, and an integer t.

A number is called zero-free if none of its digits are 0.

Return a string representing the smallest zero-free number greater than or equal to num such that the product of its digits is divisible by t. If no such number exists, return "-1".

 
Example 1:


Input: num = "1234", t = 256

Output: "1488"

Explanation:

The smallest zero-free number that is greater than 1234 and has the product of its digits divisible by 256 is 1488, with the product of its digits equal to 256.


Example 2:


Input: num = "12355", t = 50

Output: "12355"

Explanation:

12355 is already zero-free and has the product of its digits divisible by 50, with the product of its digits equal to 150.


Example 3:


Input: num = "11111", t = 26

Output: "-1"

Explanation:

No number greater than 11111 has the product of its digits divisible by 26.


 
Constraints:


	2 <= num.length <= 2 * 105
	num consists only of digits in the range ['0', '9'].
	num does not contain leading zeros.
	1 <= t <= 1014

## Solution

**Language:** C++  
**Runtime:** 439 ms (beats 10.35%)  
**Memory:** 152.4 MB (beats 10.35%)  
**Submitted:** 2026-08-07T02:31:27.419Z  

```cpp
class Solution {
    // Check if prime factors of t consist only of 2, 3, 5, 7
    bool getFactors(long long t, int& cnt2, int& cnt3, int& cnt5, int& cnt7) {
        cnt2 = cnt3 = cnt5 = cnt7 = 0;
        while (t % 2 == 0) { cnt2++; t /= 2; }
        while (t % 3 == 0) { cnt3++; t /= 3; }
        while (t % 5 == 0) { cnt5++; t /= 5; }
        while (t % 7 == 0) { cnt7++; t /= 7; }
        return t == 1; // Returns false if t has prime factors > 7
    }

    // Returns minimum digits required to cover factor counts (2^a * 3^b * 5^c * 7^d)
    int minDigits(int a, int b, int c, int d) {
        a = max(0, a);
        b = max(0, b);
        c = max(0, c);
        d = max(0, d);

        int min_23 = 1e9;
        // Iterate over count of '6's (uses one 2 and one 3)
        for (int k6 = 0; k6 <= min(a, b); ++k6) {
            int rem2 = a - k6;
            int rem3 = b - k6;
            int digits2 = (rem2 + 2) / 3; // using 8s
            int digits3 = (rem3 + 1) / 2; // using 9s
            min_23 = min(min_23, k6 + digits2 + digits3);
        }
        return c + d + min_23;
    }

    // Deducts prime factors provided by digit `d`
    void consumeDigit(int d, int& a, int& b, int& c, int& d_fact) {
        if (d == 2) a -= 1;
        else if (d == 3) b -= 1;
        else if (d == 4) a -= 2;
        else if (d == 5) c -= 1;
        else if (d == 6) { a -= 1; b -= 1; }
        else if (d == 7) d_fact -= 1;
        else if (d == 8) a -= 3;
        else if (d == 9) b -= 2;
    }

    // Constructs lexicographically smallest valid string of length `len`
    string buildSmallestSuffix(int len, int a, int b, int c, int d) {
        string res = "";
        for (int i = 0; i < len; ++i) {
            for (int digit = 1; digit <= 9; ++digit) {
                int na = a, nb = b, nc = c, nd = d;
                consumeDigit(digit, na, nb, nc, nd);
                if (minDigits(na, nb, nc, nd) <= len - 1 - i) {
                    res += to_string(digit);
                    a = na; b = nb; c = nc; d = nd;
                    break;
                }
            }
        }
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        int req2, req3, req5, req7;
        if (!getFactors(t, req2, req3, req5, req7)) {
            return "-1";
        }

        int n = num.size();

        // Check if `num` is zero-free and its product is already divisible by t
        bool has_zero = false;
        int first_zero = -1;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                has_zero = true;
                first_zero = i;
                break;
            }
        }

        if (!has_zero) {
            int a = req2, b = req3, c = req5, d = req7;
            for (char ch : num) {
                consumeDigit(ch - '0', a, b, c, d);
            }
            if (a <= 0 && b <= 0 && c <= 0 && d <= 0) {
                return num;
            }
        }

        int limit = has_zero ? first_zero : n - 1;

        // Compute factor requirements for prefixes
        vector<vector<int>> pref_req(n + 1, vector<int>{req2, req3, req5, req7});
        for (int i = 0; i < limit; ++i) {
            pref_req[i + 1] = pref_req[i];
            consumeDigit(num[i] - '0', pref_req[i + 1][0], pref_req[i + 1][1], pref_req[i + 1][2], pref_req[i + 1][3]);
        }

        // Try matching a prefix of length `i` and replacing digit `i` with a larger digit
        for (int i = limit; i >= 0; --i) {
            int start_digit = (i < n && (!has_zero || i < first_zero)) ? (num[i] - '0' + 1) : 1;

            for (int digit = start_digit; digit <= 9; ++digit) {
                int a = pref_req[i][0], b = pref_req[i][1], c = pref_req[i][2], d = pref_req[i][3];
                consumeDigit(digit, a, b, c, d);

                int rem_len = n - 1 - i;
                if (minDigits(a, b, c, d) <= rem_len) {
                    string prefix = num.substr(0, i) + to_string(digit);
                    string suffix = buildSmallestSuffix(rem_len, a, b, c, d);
                    return prefix + suffix;
                }
            }
        }

        // If no solution of length n exists, expand length to (n + 1) or needed minimum length
        int min_len = minDigits(req2, req3, req5, req7);
        int target_len = max(n + 1, min_len);
        return buildSmallestSuffix(target_len, req2, req3, req5, req7);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/smallest-divisible-digit-product-ii/)