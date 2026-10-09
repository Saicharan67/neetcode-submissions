class Solution {
public:
    vector<vector<int>> dp;
    int recurr(int l, int r, vector<int>& nums){
       
       if(r>=nums.size() || l<0){
            return 0;
       }

       int maxi = 0;
       for(int i = l; i<=r; i++){

           
            int a = 0 ;
            int b = 0 ;
            if(dp[l][i-1]!=-1){
                a = dp[l][i-1];
            }else{
                a = recurr(l,i-1,nums);
            }
             if(dp[i+1][r]!=-1){
                b = dp[i+1][r];
            }else{
                b = recurr(i+1,r,nums);
            }
            maxi = max(maxi,nums[l-1]*nums[i]*nums[r+1]+a+b) ;

       }

       return dp[l][r]=maxi;
        
    }
    int maxCoins(vector<int>& nums) {
        dp.assign(nums.size()+3,vector<int>(nums.size()+3,-1));
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        return recurr(1,nums.size()-2,nums);
    }
};
