
class Solution {
public:
    int ans = 0;
    int total = 0;

    void solve(vector<vector<int>>& grid, int r, int c, int count) {
        int m = grid.size();
        int n = grid[0].size();

        // Reached ending square
        if (grid[r][c] == 2) {
            if (count == total)
                ans++;
            return;
        }

        int temp = grid[r][c];
        grid[r][c] = -1;  // Mark visited

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                grid[nr][nc] != -1) {

                solve(grid, nr, nc, count + 1);
            }
        }

        grid[r][c] = temp;  // Backtrack
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int sr = 0, sc = 0;

        // Count all non-obstacle squares
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1)
                    total++;

                if (grid[i][j] == 1) {
                    sr = i;
                    sc = j;
                }
            }
        }

        solve(grid, sr, sc, 1);

        return ans;
    }
};
