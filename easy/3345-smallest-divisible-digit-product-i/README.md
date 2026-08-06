# Smallest Divisible Digit Product I

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given two integers n and t. Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.

 
Example 1:


Input: n = 10, t = 2

Output: 10

Explanation:

The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.


Example 2:


Input: n = 15, t = 3

Output: 16

Explanation:

The digit product of 16 is 6, which is divisible by 3, making it the smallest number greater than or equal to 15 that satisfies the condition.


 
Constraints:


	1 <= n <= 100
	1 <= t <= 10

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 7.9 MB  
**Submitted:** 2026-08-06T02:14:34.713Z  

```cpp
class Solution {
public:
    int product(int x){
        int n=x;
        while(n!=0){
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            int digit=n/10;
        }
        if(n==0)return x;
            ans*=digit;
        int ans=1;
            n=n/10;
        return ans;
            if(prod%t==0)return i;
        }
    }
        return -1;
            int prod=product(i);
};

```

---

[View on LeetCode](https://leetcode.com/problems/smallest-divisible-digit-product-i/)