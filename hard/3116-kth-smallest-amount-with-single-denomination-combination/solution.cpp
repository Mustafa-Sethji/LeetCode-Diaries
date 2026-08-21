class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        // Count valid distinct amounts <= x
        auto count = [&](long long x) -> long long {
            long long cnt = 0;

            // Iterate over every non-empty subset
            for (int mask = 1; mask < (1 << n); mask++) {
                long long l = 1;
                bool overflow = false;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        long long g = gcd(l, (long long)coins[i]);

                        // Prevent LCM from becoming unnecessarily large
                        if (l / g > x / coins[i]) {
                            overflow = true;
                            break;
                        }

                        l = (l / g) * coins[i];
                    }
                }

                if (overflow || l > x) continue;

                // Inclusion-Exclusion
                if (__builtin_popcount(mask) % 2 == 1)
                    cnt += x / l;
                else
                    cnt -= x / l;
            }

            return cnt;
        };

        long long low = 1;
        long long high = 1LL * k * (*min_element(coins.begin(), coins.end()));

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};