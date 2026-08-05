class Solution {
public:
    int hammingWeight(uint32_t n) {

        int res=0;

        while(n){
            n = n&(n-1);
            res++;
        }

        return res;


    }
    vector<int> countBits(int n) {
        vector<int> res;

        for(int i = 0; i<=n; i++){

            res.push_back(hammingWeight(i));
        }

        return res;
    }
};
