class Solution {
public:

    int recurr(int s1, int s2, string t1, string t2){
        if(s1>=t1.size() || s2>=t2.size()){
            return 0;
        }

        if(t1.substr(s1,1)==t2.substr(s2,1)){
            return 1 + recurr(s1+1,s2+1,t1,t2);
        }else{
            return max(recurr(s1+1,s2,t1,t2),recurr(s1,s2+1,t1,t2));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {

         int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    
        
    }
};
