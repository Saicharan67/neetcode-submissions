class Solution {
public:
    struct Point {
        int r;
        int c;
    };
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;

        int m = grid.size();
        int n = grid[0].size();

         deque<Point> dq;

        int fresh = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 2) {
                    dq.push_back({r, c});
                    grid[r][c]=0;
                }else if(grid[r][c]==1){
                    fresh++;
                }
            }
        }

        if(fresh==0){
            return 0;
        }
        int directions[4][2] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };
        int level = 0;
         while (!dq.empty()) {
           
           int size = dq.size();

           for(int i = 0; i<size; i++){

             auto p = dq.front();
             dq.pop_front();

            for (auto& dir : directions) {
                int nr = p.r + dir[0];
                int nc = p.c + dir[1];

                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n)
                    continue;

               
                if (grid[nr][nc] == 1){
                     grid[nr][nc] = 2;
                     fresh--;
                    dq.push_back({nr, nc});
                }
                

               
            }
        }
        level++;
    }

    return fresh>0?-1:level-1;
    }
};
