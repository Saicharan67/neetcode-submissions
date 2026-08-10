class Solution {
public:
void backtrack(vector<vector<int>> &res,vector<int>curr,vector<int> nums,int target,int start){
       
        if(target==0){       
            res.push_back(curr);
            return;
        }
        if(target<2 ){
            return;
        }

        for(int i = start; i<nums.size(); i++){

            curr.push_back(nums[i]);
            backtrack(res,curr,nums,target-nums[i],i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(res,curr,nums,target,0);
        return res;

    }
};
