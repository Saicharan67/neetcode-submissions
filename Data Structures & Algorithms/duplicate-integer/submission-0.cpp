class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for(auto num:nums){

            if(seen.count(num)==0){

                seen.insert(num);
            }else{
                return true;
            }
        }
        return false;
        
    }
};