class Solution {
public:
    struct Point {
        int r;
        int c;
    };

    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return;

        int m = grid.size();
        int n = grid[0].size();

        queue<Point> q;

        // Put all treasures into queue
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        int directions[4][2] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            for (auto& dir : directions) {
                int nr = p.r + dir[0];
                int nc = p.c + dir[1];

                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n)
                    continue;

                // Only visit empty land (INF)
                if (grid[nr][nc] != INT_MAX)
                    continue;

                grid[nr][nc] = grid[p.r][p.c] + 1;
                q.push({nr, nc});
            }
        }
    }
};