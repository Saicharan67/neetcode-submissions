class Solution {
public:
    void dfs(unordered_map<int,vector<int>> &mp ,vector<int> &v, int idx){

        if(v[idx]){
            return;
        }

        v[idx]=1;
        for(int i:mp[idx]){
            
            dfs(mp,v,i);
        }

        return;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> mp;
        vector<int> v(n,0);

        for(auto it:edges){

            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);


        }
        int res = 0;
        for(int i = 0; i<n ; i++){

            if(v[i]==0){
                res+=1;

                dfs(mp,v,i);
            }
        }
        return res;

    }
};

