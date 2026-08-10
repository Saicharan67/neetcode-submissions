class Solution {
public:
void backtrack(vector<vector<int>> &res,vector<int>curr,vector<int> nums){
       
        if(curr.size()==nums.size()){
            res.push_back(curr);
        }
        if(curr.size()>nums.size()){
            return;
        }

        for(int i = 0; i<nums.size(); i++){
            if (count(curr.begin(), curr.end(), nums[i]) > 0) continue;
            curr.push_back(nums[i]);
            backtrack(res,curr,nums);
            curr.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(res,curr,nums);
        return res;

    }
};
