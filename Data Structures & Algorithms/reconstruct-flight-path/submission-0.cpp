class Solution {
public:

    void dfs(string r, vector<string> &res, unordered_map<string, vector<string>> &mp){

        while(!mp[r].empty()){
            auto it = mp[r].begin();
            string v = *it;
            mp[r].erase(it);
            dfs(v,res,mp);
        }
        res.push_back(r);
        return;

    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        unordered_map<string, vector<string>> mp;
       

        for (auto& t : tickets) {
            // each t is a vector<string> of size 2
            mp[t[0]].push_back(t[1]);
           
        }

        for (auto& [k, v] : mp) {
            sort(v.begin(), v.end());
        }

        vector<string> res;
        

        dfs("JFK",res,mp);
        reverse(res.begin(),res.end());

        return res;

        
    }
};
