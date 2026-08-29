class Solution {
public:
    bool dfs(unordered_map<int,vector<int>> &mp ,vector<int> &v, int idx, int prev){

        if(v[idx]){
            return false;
        }

        v[idx]=1;
        for(int i:mp[idx]){
            if(prev==i){
                continue;
            }
            if(!dfs(mp,v,i,idx)){
                return false;
            }
        }

        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {

        unordered_map<int,vector<int>> mp;
        vector<int> v(n,0);

        for(auto it:edges){

            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);


        }

        if(!dfs(mp,v,0,-1)) return false;

        for(int i = 0; i<n ; i++){

            if(v[i]==0){
                return false;
            }
        }

        return true ;
    }
};
