class Solution {
public:

    bool recurr(int i, int j, const string& s1, const string& s2, const string& s3, vector<vector<int>>& memo){
        if(i==s1.size() && j==s2.size()){
            return true;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int k = i+j;
        bool choice1 = false, choice2 = false;
        if(i<s1.size() && s1[i]==s3[k]){
            choice1 = recurr(i + 1, j, s1, s2, s3, memo);
        }
        if(j<s2.size() && s2[j]==s3[k]){
            choice2 = recurr(i, j+1, s1, s2, s3, memo);
        }

        return memo[i][j] = (choice1 || choice2);
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }

        // memo table initialized to -1
        vector<vector<int>> memo(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return recurr(0,0,s1,s2,s3,memo);
        
    }
};
