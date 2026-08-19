#include <vector>
#include <algorithm>
using namespace std;

class DSU {
    vector<int> Parent, Size;
public:
    DSU(int n) {
        Parent.resize(n);
        Size.resize(n);
        for (int i = 0; i < n; i++) {
            Parent[i] = i;
            Size[i] = 0;   // initialize to 0, will set to 1 only for land cells
        }
    }

    int find(int n) {
        if (n != Parent[n]) {
            Parent[n] = find(Parent[n]);
        }
        return Parent[n];
    }

    void unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;

        if (Size[pv] >= Size[pu]) {
            Parent[pu] = pv;
            Size[pv] += Size[pu];
        } else {
            Parent[pv] = pu;
            Size[pu] += Size[pv];
        }
    }

    int maxfind() {
        return *max_element(Size.begin(), Size.end());
    }

    void setLand(int idx) {
        Size[idx] = 1;  // mark land cells with size 1
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        DSU dsu(ROWS * COLS);

        auto index = [&](int r, int c) {
            return r * COLS + c;
        };

        int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        // initialize DSU sizes only for land cells
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    dsu.setLand(index(r, c));
                }
            }
        }

        // union adjacent land cells
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    for (auto& d : directions) {
                        int nr = r + d[0], nc = c + d[1];
                        if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && grid[nr][nc] == 1) {
                            dsu.unionBySize(index(r, c), index(nr, nc));
                        }
                    }
                }
            }
        }

        return dsu.maxfind();
    }
};
