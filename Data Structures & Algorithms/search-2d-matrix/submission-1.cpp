class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mt, int target) {
        
        int m = mt.size();
        int n = mt[0].size();

        int l = 0;
        int r = m*n - 1;

        while(l<=r){

            int mid = l + (r-l)/2;

            int temp = mt[mid/n][mid%n];

            if(temp > target){

                r = mid - 1;
            }else if(temp==target){
                return true;
            }else{
                l = mid+1;
            }
        }

        return false;
    }
};
