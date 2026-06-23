class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        

        int l = 0;
        int r = numbers.size()-1;
        int temp = 0;
        while(l<r){

            temp = numbers[l]+numbers[r];

            if(target>temp){
                l++;
            }else if(target<temp){
                r--;
            }else{
                return {l+1,r+1};
            }
            
        }
        return {};

    }
};
