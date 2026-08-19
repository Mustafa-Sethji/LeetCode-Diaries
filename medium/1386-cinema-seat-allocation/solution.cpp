class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        map<int, set<int>> reserved;

        // Store reserved seats row-wise
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            // Only seats 2 to 9 matter
            if (col >= 2 && col <= 9) {
                reserved[row].insert(col);
            }
        }

        // Every completely empty row can accommodate 2 groups
        long long ans = 2LL * n;

        // Process only rows having relevant reservations
        for (auto &[row, seats] : reserved) {

            // Remove the default contribution of this row
            ans -= 2;

            bool left = true;   // seats 2,3,4,5
            bool middle = true; // seats 4,5,6,7
            bool right = true;  // seats 6,7,8,9

            // Check left block
            for (int i = 2; i <= 5; i++) {
                if (seats.count(i)) {
                    left = false;
                    break;
                }
            }

            // Check middle block
            for (int i = 4; i <= 7; i++) {
                if (seats.count(i)) {
                    middle = false;
                    break;
                }
            }

            // Check right block
            for (int i = 6; i <= 9; i++) {
                if (seats.count(i)) {
                    right = false;
                    break;
                }
            }

            int groups = 0;

            if (left && right) {
                groups = 2;
            }
            else if (left || middle || right) {
                groups = 1;
            }

            ans += groups;
        }

        return ans;
    }
};