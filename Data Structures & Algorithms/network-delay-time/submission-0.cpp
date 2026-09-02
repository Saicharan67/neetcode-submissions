class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<int> vis(n, 10000);
        unordered_map<int, vector<vector<int>>> mp;

        for (auto t : times) {
            mp[t[0]].push_back({t[1], t[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, k});
        vis[k-1] = 0;
        while (!pq.empty()) {

            auto p = pq.top();
            pq.pop();
            if (p.first > vis[p.second-1]) continue;

            for (auto i : mp[p.second]) {
                if (p.first + i[1] < vis[i[0]-1]) {
                    vis[i[0]-1] = p.first + i[1];   // <-- missing semicolon fixed
                    pq.push({vis[i[0]-1], i[0]});
                }
            }
        }

        for (auto z : vis) {
            cout << z << "\n";
        }

        int maxVal = *max_element(vis.begin(),vis.end());

        return (maxVal==10000)?-1:maxVal;
    }
};
