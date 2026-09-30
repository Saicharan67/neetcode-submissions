class Solution {
public:
    int recurr(int j, int i, vector<int>& nums,vector<vector<int>> &dp){

        if(i>=nums.size()){
            return 0;
        }
        if(dp[j+1][i]!=-1){
            return dp[j+1][i];
        }
        int a = 0;
        int b = recurr(j,i+1,nums,dp);
        if(j==-1 || nums[j]<nums[i]){
           
            a = 1 + recurr(i,i+1,nums,dp);
            
        }
       
        dp[j+1][i] = max(a,b);
        return dp[j+1][i];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
    
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return recurr(-1,0,nums,dp);
    }
};
