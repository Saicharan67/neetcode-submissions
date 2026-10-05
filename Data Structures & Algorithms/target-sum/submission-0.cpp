class Solution {
public:
unordered_map<string, int> memo;
    int recurr(int idx, int target, int currSum, vector<int> &nums){
        if(idx>=nums.size()){
            if(target==currSum){
                return 1;
            }else{
                return 0;
            }

        }
        string key = to_string(idx) + "," + to_string(currSum);
 
        if (memo.find(key) != memo.end()) {
        return memo[key];
        }
        return memo[key] = recurr(idx+1,target,currSum+nums[idx],nums)+recurr(idx+1,target,currSum-nums[idx],nums);
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        return recurr(0,target,0,nums);
        
    }
};
