class Solution {
public:
    int recurr(int i, vector<int>& coins, int amount, vector<vector<int>>& dp){

        if(amount==0){
            return 1;
        }
        
        if(amount<0 || i>=coins.size()){
            return 0;
        }
        if (dp[i][amount] != -1)
            return dp[i][amount];

        int take = recurr(i,coins,amount-coins[i],dp);

        int skip = recurr(i+1,coins,amount,dp);


       
      return dp[i][amount] = take+skip ;
           

    }
    int change(int amount, vector<int>& coins) {
          if(amount==0){
            return 1;
        }
        


      vector<vector<int>> dp(
            coins.size(),
            vector<int>(amount + 1, -1)
        );


        int ans =
            recurr(
                0,
                coins,
                amount,
                dp
            );


          return ans;
        
    }
};
