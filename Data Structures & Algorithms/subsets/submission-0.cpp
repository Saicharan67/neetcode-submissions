class Solution {
public:

    void backtrack(vector<vector<int>> &res,vector<int>curr,vector<int> nums,int idx){
       
            res.push_back(curr);
          

        for(int i = idx; i<nums.size(); i++){

            curr.push_back(nums[i]);
            backtrack(res,curr,nums,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(result,curr,nums,0);

        return result;
    }
};
