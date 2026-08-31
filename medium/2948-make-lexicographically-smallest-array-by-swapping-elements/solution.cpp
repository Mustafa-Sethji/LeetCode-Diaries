class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        // Store indices
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        // Sort indices according to their values
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });

        vector<int> ans(n);

        for (int i = 0; i < n; ) {

            // Find the group
            int j = i + 1;

            while (j < n &&
                   nums[idx[j]] - nums[idx[j - 1]] <= limit) {
                j++;
            }

            // Indices belonging to this group
            vector<int> positions(idx.begin() + i, idx.begin() + j);

            // Put positions in original index order
            sort(positions.begin(), positions.end());

            // Smallest values go to smallest indices
            for (int k = i; k < j; k++) {
                ans[positions[k - i]] = nums[idx[k]];
            }

            i = j;
        }

        return ans;
    }
};