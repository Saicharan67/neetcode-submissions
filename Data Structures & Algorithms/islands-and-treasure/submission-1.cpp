#include <vector>
#include <deque>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        deque<pair<int,int>> dq;
        
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                   dq.push_back({i, j});
                }
            }
        }
        
        int dist = 0;
        vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int level = 1;

        while(dq.size()){
            int sz = dq.size();

            for(int i = 0; i < sz; i++){
                auto dir = dq.front();
                dq.pop_front();

                for(auto rc : dirs){
                    int curR = rc[0] + dir.first;
                    int curC = rc[1] + dir.second;

                    if(curR < 0 || curC < 0 || curR >= n || curC >= m){
                        continue;
                    }
                    if(grid[curR][curC] != -1 || grid[curR][curC] != 0){
                        if(grid[curR][curC] > level){
                            grid[curR][curC] = level;
                            dq.push_back({curR, curC});
                        }
                    }
                }
            }
            level += 1;
        }

        return;
    }
};