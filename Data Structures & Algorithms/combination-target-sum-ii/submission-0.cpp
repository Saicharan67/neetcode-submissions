class Solution {
public:
void backtrack(vector<vector<int>> &res,vector<int>curr,vector<int> nums,int target,int start){
       
        if(target==0){       
            res.push_back(curr);
            return;
        }
        if(target<1 ){
            return;
        }

        for(int i = start; i<nums.size(); i++){
            if(i > start && nums[i] == nums[i-1]) continue;
            curr.push_back(nums[i]);
            backtrack(res,curr,nums,target-nums[i],i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(res,curr,candidates,target,0);
        return res;
    }
};
