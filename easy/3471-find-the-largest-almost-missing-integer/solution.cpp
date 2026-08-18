class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // Case 1: whole array is one subarray
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Count frequency of every number
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        // Case 2: every element is its own subarray
        if (k == 1) {
            int ans = -1;

            for (auto &[x, count] : freq) {
                if (count == 1) {
                    ans = max(ans, x);
                }
            }

            return ans;
        }

        // Case 3: 1 < k < n
        int ans = -1;

        if (freq[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }

        if (freq[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};
