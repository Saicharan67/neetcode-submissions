class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int n = nums.size(); 
         for(int i=0;i<n;i++){

            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            int l = i+1;    
            int r = n-1;
            int target = 0 - nums[i];
            while(l<r){

                int temp = nums[l]+nums[r];
                if(temp<target){
                    l++;
                }else if (temp>target){
                    r--;
                }else{

                    res.push_back({nums[i],nums[l],nums[r]});
                    while(l<r && nums[l]==nums[l+1]) l++;
                    while(l<r && nums[r]==nums[r-1]) r--;
                    l++;
                    r--;
                }


            }
       



         }
         return res;
    }
};
