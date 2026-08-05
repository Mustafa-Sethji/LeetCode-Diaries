
        function<void(int)> dfs = [&](int u) {
            vis[u] = 1;
            for (int v : graph[u]) {
                if (!vis[v])
                    dfs(v);
            }
        };

        dfs(k);

        // Check if any non-suspicious method calls a suspicious one
        for (auto &e : invocations) {
            int u = e[0], v = e[1];
            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        vector<int> ans;
        vector<int> vis(n, 0);

        for (auto &e : invocations)
            graph[e[0]].push_back(e[1]);
        vector<vector<int>> graph(n);

public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
class Solution {
