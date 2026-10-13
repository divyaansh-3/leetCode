class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);

        // Build the graph
        for (auto& d : dislikes) {
            int u = d[0];
            int v = d[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 0 = uncolored, 1 and -1 = two groups
        vector<int> color(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (color[i] != 0)
                continue;

            queue<int> q;
            q.push(i);
            color[i] = 1;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    // Both people cannot be in the same group
                    if (color[v] == color[u])
                        return false;

                    // Assign the opposite group
                    if (color[v] == 0) {
                        color[v] = -color[u];
                        q.push(v);
                    }
                }
            }
        }

        return true;
    }
};