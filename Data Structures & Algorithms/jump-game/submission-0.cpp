class Solution {
public:
    vector<int> dp;
    bool recurr(int idx, vector<int>& nums){
        if(idx>=nums.size()-1){
            return true;
        }
        if(nums[idx]==0){
            return false;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        for(int i = 1;i<nums[idx]+1;i++){
            if(recurr(idx+i,nums)){
                return dp[idx]=true;
            }
        }

        return dp[idx]=false;
    }
    bool canJump(vector<int>& nums) {
        dp.assign(nums.size()+1,-1);
        return recurr(0,nums);
    }
};
