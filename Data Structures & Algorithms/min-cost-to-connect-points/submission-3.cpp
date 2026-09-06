#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        unordered_map<int, vector<vector<int>>> mp;
        int n = points.size();
      //  cout << "Number of points: " << n << endl;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                mp[i].push_back({j, dist});
                mp[j].push_back({i,dist});
              //  cout << "Edge added: " << i << " -> " << j << " with weight " << dist << endl;
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, 0});
     //   cout << "Initial push: node=0, weight=0" << endl;

        vector<int> vis(n, 0);
        int sum = 0;

        while (!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();
        //    cout << "Popped from PQ: node=" << u << ", weight=" << w << endl;

            if (vis[u]) {
           //     cout << "Node " << u << " already visited, skipping." << endl;
                continue;
            }

            vis[u] = 1;
            sum += w;
//cout << "Visiting node " << u << ", total sum=" << sum << endl;
//
            for (auto& vec : mp[u]) {
                int v = vec[0];
                int wt = vec[1];
                if (!vis[v]) {
                    pq.push({wt, v});
                   // cout << "Pushed to PQ: node=" << v << ", weight=" << wt << endl;
                }
            }
        }

       // cout << "Final MST cost: " << sum << endl;
        return sum;
    }
};
