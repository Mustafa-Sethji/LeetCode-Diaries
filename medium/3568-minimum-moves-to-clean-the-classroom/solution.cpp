class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        int sr, sc;
        int litterCount = 0;

        // Assign an index to every litter cell
        vector<vector<int>> id(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }

        int fullMask = (1 << litterCount) - 1;

        // maxEnergy[r][c][mask] = maximum energy with which
        // we have reached (r,c) after collecting 'mask'
        vector<vector<vector<int>>> maxEnergy(
            n,
            vector<vector<int>>(
                m,
                vector<int>(1 << litterCount, -1)
            )
        );

        // {row, col, energy, mask}
        queue<array<int, 4>> q;

        q.push({sr, sc, energy, 0});
        maxEnergy[sr][sc][0] = energy;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, e, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == fullMask)
                    return moves;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                        continue;

                    // Wall
                    if (classroom[nr][nc] == 'X')
                        continue;

                    // One move consumes one energy
                    int ne = e - 1;

                    if (ne < 0)
                        continue;

                    int nmask = mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << id[nr][nc]);
                    }

                    // Recharge at R
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    // If we've already reached this state
                    // with equal or greater energy, skip it.
                    if (maxEnergy[nr][nc][nmask] >= ne)
                        continue;

                    maxEnergy[nr][nc][nmask] = ne;

                    q.push({nr, nc, ne, nmask});
                }
            }

            moves++;
        }

        return -1;
    }
};