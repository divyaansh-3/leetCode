class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
          int n = words.size();

        vector<vector<int>> overlap(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int len = min(words[i].size(), words[j].size());

                for (int k = len; k >= 0; k--) {
                    if (words[i].substr(words[i].size() - k) ==
                        words[j].substr(0, k)) {
                        overlap[i][j] = k;
                        break;
                    }
                }
            }
        }

        int total = 1 << n;
        vector<vector<int>> dp(total, vector<int>(n, -1));
        vector<vector<int>> parent(total, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
            dp[1 << i][i] = words[i].size();

        for (int mask = 1; mask < total; mask++) {
            for (int last = 0; last < n; last++) {
                if (!(mask & (1 << last)) || dp[mask][last] == -1)
                    continue;

                for (int next = 0; next < n; next++) {
                    if (mask & (1 << next))
                        continue;

                    int newMask = mask | (1 << next);
                    int cost = dp[mask][last] +
                               words[next].size() - overlap[last][next];

                    if (dp[newMask][next] == -1 ||
                        cost < dp[newMask][next]) {
                        dp[newMask][next] = cost;
                        parent[newMask][next] = last;
                    }
                }
            }
        }

        int mask = total - 1;
        int last = 0;

        for (int i = 1; i < n; i++) {
            if (dp[mask][i] < dp[mask][last])
                last = i;
        }

        vector<int> path;

        while (last != -1) {
            path.push_back(last);
            int prev = parent[mask][last];
            mask ^= (1 << last);
            last = prev;
        }

        reverse(path.begin(), path.end());

        string ans = words[path[0]];

        for (int i = 1; i < n; i++) {
            int a = path[i - 1];
            int b = path[i];

            ans += words[b].substr(overlap[a][b]);
        }

        return ans;
    }
};