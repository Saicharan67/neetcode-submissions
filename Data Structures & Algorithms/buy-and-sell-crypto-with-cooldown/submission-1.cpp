class Solution {
public:
    vector<vector<int>> memo;
    int recurr(int state, int idx, vector<int>& prices){
        if(idx>=prices.size()){
            return 0;
        }
        if(memo[idx][state]!=-1) return memo[idx][state];

        if(state==0){
            return memo[idx][state] = max(-prices[idx]+recurr(1,idx+1,prices),recurr(0,idx+1,prices));
        }
        if(state==1){
            return memo[idx][state] = max(prices[idx]+recurr(2,idx+1,prices),recurr(1,idx+1,prices));
        }
        if(state==2){
            return memo[idx][state] = recurr(0,idx+1,prices);
        }

        return 0;

    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        memo.assign(n, vector<int>(3, -1));
        return recurr(0, 0, prices);

        
    }
};
