class Solution {
public:
    int recurr(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        if (j >= t.size()) return 1;   // matched entire t
        if (i >= s.size()) return 0;   // ran out of s

        if (dp[i][j] != -1) return dp[i][j];  // return cached result

        int a = 0, b = 0;
        if (s[i] == t[j]) {
            a = recurr(i + 1, j + 1, s, t, dp);  // match current char
        }
        b = recurr(i + 1, j, s, t, dp);          // skip current char in s

        return dp[i][j] = a + b;
    }

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return recurr(0, 0, s, t, dp);
    }
};
