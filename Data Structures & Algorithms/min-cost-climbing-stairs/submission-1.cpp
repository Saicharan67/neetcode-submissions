class Solution {
public:
   
    int recurr(int idx, vector<int> &cost,vector<int> &cache){


        if(idx>=cost.size()){
            return 0;
        }

        if(cache[idx]!=-1){
            return cache[idx];
        }

        cache[idx] = cost[idx] + min(recurr(idx+1,cost,cache),recurr(idx+2,cost,cache));

        return cache[idx];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> cache(cost.size(),-1);
        return min(recurr(0,cost,cache),recurr(1,cost,cache));
    }
};
