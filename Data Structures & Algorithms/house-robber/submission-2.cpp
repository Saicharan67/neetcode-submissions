class Solution {
public:
    int recurr(int i, int n, vector<int>& nums,vector<int>& memo) {
        if (i>= n) {
            return 0;
        }
        if(memo[i]!=-1){
            return memo[i];
        }
        int op1 = nums[i] + recurr(i + 2, n, nums,memo);

        int op2 = 0;
        if(i+1<n){
            op2 =  nums[i + 1] + recurr(i + 3, n, nums,memo);
        }

        memo[i] = max(op1,op2);
        return memo[i];
    }

    int rob(vector<int>& nums) {
        std::vector<int> memo(nums.size(), -1);
        return recurr(0, nums.size(), nums,memo);
    }
};
