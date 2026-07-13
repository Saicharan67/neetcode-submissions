class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        

        unordered_map<int,int> m;

        for(int i = 0; i<nums.size(); i++){
            if(i<=k){
                if(m.count(nums[i])>0){
                    return true;
                }
                m[nums[i]]=i;
            }else{
                m.erase(nums[i-k-1]);
                if(m.count(nums[i])>0){
                    return true;
                }
                m[nums[i]] = i;

            }
        }

        return false;
    }
};