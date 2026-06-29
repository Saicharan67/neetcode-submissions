class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        if(n<1){
            return 0;
        }


    int maxi = prices[n-1];
    int res = 0;

    for(int i = n-2;i>=0;i--){

        if(prices[i]>maxi){
            maxi = prices[i];
        }else{
            res = max(res,maxi-prices[i]);
        }
    }

    return res;
        
    }
};
