#include <numeric> 
class Solution {
public:
    int targSum = 0;
    bool recurr(int i , int currSum, vector<int>& nums,vector<vector<int>>& dp){
        if(currSum==targSum){
            return true;
        }
      if (i >= nums.size() || currSum > targSum) return false;
         if (dp[i][currSum] != -1) return dp[i][currSum];

        bool k1 = recurr(i+1,currSum, nums,dp);
        bool k2 = false;
        if(currSum+nums[i]<=targSum){
            k2 = recurr(i+1, currSum+nums[i],nums,dp);
        }

         return dp[i][currSum] = (k1 || k2);
    }
    bool canPartition(vector<int>& nums) {

        int sum = std::accumulate(nums.begin(), nums.end(), 0);

        if(sum%2){
            return false;
        }
        targSum = sum/2;
        vector<vector<int>> dp(nums.size(), vector<int>(targSum+1, -1));
        
        return recurr(0,0,nums,dp);
    }
};
