class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMax = 1;
        int curMin = 1;

        for(auto num:nums){
            if(num==0){
                curMin = 1;
                curMax = 1;
            }
            int tmp = curMax*num;
            curMax = max(max(num*curMin, num*curMax),num);
            curMin = min(min(tmp,num*curMin),num);
            res = max(res,curMax);

        }

        return res;

    }
};
