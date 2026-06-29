class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int left = 0;
        unordered_map<int,int> count;
        int maxi = 0;
        int res = 0;
        
        for(int r = 0;r<s.length();r++){

            count[s[r]]+=1;
            maxi = max(maxi,count[s[r]]);

            while(((r-left+1)-maxi)>k){

                count[s[left]]-=1;
                left+=1;
            }
            res = max(res,r-left+1);
        }

        return res;
    }
};
