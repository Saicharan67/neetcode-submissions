class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {


        int len = nums.size();

        vector<int> prefix(len,1);
        vector<int> suffix(len,1);

        for(int i=0;i<len;i++){

            if(i!=0){
                prefix[i]=nums[i]*prefix[i-1];
                suffix[len-i-1]=nums[len-i-1]*suffix[len-i];
            }else{
                prefix[i]=nums[i];
                suffix[len-i-1]=nums[len-1];
               
            }
            
        }
       // return suffix;
        vector<int> result;

        for(int i=0;i<len;i++){

            if(i!=0 && i!=len-1){

                result.push_back(prefix[i-1]*suffix[i+1]);
            }else{
                if(i==0){
                    result.push_back(suffix[i+1]);
                }
                else
                    result.push_back(prefix[i-1]);
                }
            
            }
               return result;
        }
        
     
    
};
