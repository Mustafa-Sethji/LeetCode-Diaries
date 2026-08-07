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
**Runtime:** 0 ms  
**Memory:** 8 MB  
**Submitted:** 2026-08-07T02:31:20.339Z  

```cpp
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

```

---

[View on LeetCode](https://leetcode.com/problems/smallest-divisible-digit-product-ii/)