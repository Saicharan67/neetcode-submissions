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
        if(nums.size()==1){
            return 0;
        }
        int jumps = 0;
        int maxreach = 0;
        int currentend = 0;
        for(int i = 0; i<nums.size()-1; i++){
           maxreach = max(maxreach,nums[i]+i);
           if(currentend==i){
                jumps++;
                currentend = maxreach;
                if(currentend>=nums.size()-1){
                        break;
                }
           }
           
          
        }
        return jumps;
        // dp.assign(nums.size()+1,-1);
        // return recurr(0,nums);
    }
};
