                    }
                }

                if (overflow || l > x) continue;

                // Inclusion-Exclusion
                if (__builtin_popcount(mask) % 2 == 1)
                    cnt += x / l;
                else
                    cnt -= x / l;
            }

            return cnt;
        };

        long long low = 1;
        long long high = 1LL * k * (*min_element(coins.begin(), coins.end
        ()));

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};
