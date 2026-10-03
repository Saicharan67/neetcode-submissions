class Solution {
public:
    int recurr(int i, int n, vector<int>& nums,vector<int>& memo) {
        if (i>= n) {
            return 0;
        }
        if(memo[i]!=-1){
            return memo[i];
        }
        int op1 = nums[i] + recurr(i + 2, n, nums,memo);

        int op2 = recurr(i+1,n,nums,memo);
        

        memo[i] = max(op1,op2);
        return memo[i];
    }
    int rob(vector<int>& arr) {
        if (arr.size() == 1) return arr[0];
         vector<int> arr1(arr.begin() + 1, arr.end());
          std::vector<int> memo(arr1.size(), -1);

        // Equivalent to arr[:-1] → from start to index size-1 (exclusive of last element)
        vector<int> arr2(arr.begin(), arr.end() - 1);
         std::vector<int> memo2(arr2.size(), -1);
        int a = recurr(0, arr1.size(), arr1,memo);
        int b = recurr(0,arr2.size(),arr2,memo2);
        return max(a,b);
    }
};
