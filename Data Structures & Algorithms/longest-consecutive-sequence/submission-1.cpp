class Solution {
public:
    int longestConsecutive(vector<int>& nums) {


        unordered_set<int> s;

        for(auto num:nums){
            s.insert(num);
        }

        int res = 0;
        int temp = 1;

        for(int i = 0 ; i<nums.size(); i++){
        
            if(!s.count(nums[i]-1)){

                 int x = nums[i]+1;

                  while(1){

                        if(s.count(x)){
                            temp+=1;
                        }else{
                            break;
                        }
                        x++;
                    }
                res = max(res,temp);
                temp = 1;
            }
          

        }

        return res;


        
    }
};
