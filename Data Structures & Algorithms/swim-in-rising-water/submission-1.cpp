#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> v(n * n, 0);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({grid[0][0], 0, 0});
        

        while (!pq.empty()) {

            auto t = pq.top();
            pq.pop();

            int r = t[1];
            int c = t[2];
            if (r == n - 1 && c == n - 1) {
                return t[0];
            }
            if (v[r * n + c] == 0) {
                v[r * n + c] = 1;
            } else {
                continue;
            }
            for (auto dir : vector<pair<int,int>>{{-1,0},{0,1},{1,0},{0,-1}}) {
                int r1 = r + dir.first;
                int c1 = c + dir.second;

                if (r1 < n && r1 >= 0 && c1 < n && c1 >= 0) {
                    pq.push({max(t[0], grid[r1][c1]), r1, c1});
                }
            }
        }

        return -1; // in case destination is not reachable
    }
};
