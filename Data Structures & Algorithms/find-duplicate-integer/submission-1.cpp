class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int s = nums[0];
        int f = nums[nums[0]];
       
        while(true){

           if(s==f){
                break;
           }
           s= nums[s];
           f = nums[nums[f]];

        }

        s = nums[0];
        f = nums[f];

        while(true){
            if(s==f){
                return s;
            }
            s=nums[s];
            f=nums[f];
        }

        
    }
};
