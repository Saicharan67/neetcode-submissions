class Solution {
public:
    // Pass mp and v by reference (&) to avoid TLE from deep copies
    bool findloop(int i, unordered_map<int,vector<int>>& mp, vector<int>& v, vector<bool>& inStack) {
        if (v[i] == 2) return true;  // Already fully processed and safe
        if (inStack[i]) return false; // Found a cycle on current path

        inStack[i] = true;
        v[i] = 1; // Currently visiting

        for (auto k : mp[i]) {
            if (v[k] != 2) {
                if (!findloop(k, mp, v, inStack)) return false;
            }
        }

        inStack[i] = false; // Backtrack
        v[i] = 2; // Fully visited and safe
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& p) {
        unordered_map<int,vector<int>> mp;
        vector<int> v(numCourses, 0);
        vector<bool> inStack(numCourses, false);

        for (auto& i : p) {
            mp[i[1]].push_back(i[0]);
        }

        for(int i = 0; i< numCourses; i++){
            for(auto it:mp[i]){
                v[it]++;
            }
        }

        queue<int> q;

        for(int i = 0; i<numCourses; i++){
            if(v[i]==0) q.push(i);
        }
        vector<int> topo;
        while(q.size()){

            int temp = q.front();
            q.pop();
            topo.push_back(temp);
            for(auto it:mp[temp]){

                v[it]--;
                if(v[it]==0) q.push(it);
            }
        }

        
        return topo.size()==numCourses;
    }
};