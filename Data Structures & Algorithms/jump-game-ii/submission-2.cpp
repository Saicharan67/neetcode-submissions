class Solution {
public:
    vector<int> dp;
    int recurr(int idx, vector<int>& nums){
        if(idx>=nums.size()-1){
            return 0;
        }
       
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int mini = 10000;
        for(int i = 1;i<nums[idx]+1;i++){
            
                mini = min(mini,1+recurr(idx+i,nums));
        }

         dp[idx]=mini;

        return dp[idx];
    }
    int jump(vector<int>& nums) {
        // int maxreach = 0;
        // int count = 0;
        // if(nums.size()==1){
        //     return 0;
        // }
        // for(int i = 0; i<nums.size(); i++){
           
        //     if(maxreach<i+nums[i]){
        //         maxreach=i+nums[i];
        //         count++;
        //     }
        

        //     if(maxreach>=nums.size()-1){
        //         return count;
        //     }
        // }
        // return count;
        dp.assign(nums.size()+1,-1);
        return recurr(0,nums);
    }
};
