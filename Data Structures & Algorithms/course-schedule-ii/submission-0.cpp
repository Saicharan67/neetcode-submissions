class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {

        unordered_map<int,vector<int>> mp;
        vector<int> id(n,0);
        deque<int> dq;
        vector<int> res;

        for(auto it: pre){
            mp[it[1]].push_back(it[0]);

        }

        for(int i = 0; i<n ; i++){
            for(int j:mp[i]){

                id[j]++;
            }
        }

        for(int i = 0; i<n ; i++){
            if(id[i]==0){
                dq.push_back(i);
            }
        }


        while(dq.size()){

            int temp = dq.front();
            dq.pop_front();
            res.push_back(temp);
            for(auto it:mp[temp]){
                id[it]--;
                if(id[it]==0) dq.push_back(it);
            }
        }

        if(res.size()==n){
            return res;
        }else{
            return {};
        }

        
    }
};
