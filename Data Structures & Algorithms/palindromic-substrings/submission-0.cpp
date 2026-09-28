class Solution {
public:
    int countSubstrings(string s) {
        

        int maxlen = s.length();
       

        vector<vector<bool>> dp(s.length(),vector<bool>(s.length(),false));


        for(int i = 0; i<s.length();i++){

            dp[i][i] = true;

            for(int j = 0; j<i;j++){

                if(s[i]==s[j] && (i-j<=2 || dp[j+1][i-1])){

                    dp[j][i] = true;
                    maxlen+=1;
                }
            }
        }


        return maxlen;
        
    }
};
