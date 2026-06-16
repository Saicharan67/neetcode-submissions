class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> twoSum;

        vector<int> result;

        for(int i = 0; i<nums.size();i++){

            if(twoSum.contains(target-nums[i])){
                result.push_back(twoSum[target-nums[i]]);
                result.push_back(i);
                return result;
            }else{
                twoSum[nums[i]]=i;
            }
        }

        return result;
    }
};
