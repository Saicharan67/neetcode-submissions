class Solution {
public:
    int recurr(int i , string s,vector<int> &dp){
        if(i>=s.size()){
            return 1;
        }
        int a = 0;
        int b = 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        if(s[i]!='0'){
            if (i + 1 < s.size()) {
                int twoDigit = stoi(s.substr(i, 2));  // take 2 chars starting at i
                if (twoDigit >= 10 && twoDigit <= 26) {
                    a = recurr(i + 2, s,dp);  // recurse on next position
                }
            }
            b = recurr(i+1,s,dp);
            dp[i] =  a+b;
        }else{
            dp[i] =  0;
        }
        return dp[i];

    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        return recurr(0,s,dp);
        
    }
};
