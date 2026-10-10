class Solution {
public:
    vector<vector<int>> dp;
    int recurr(int s1, int p1, string s, string p){
        if(p1>=p.size() && s1>=s.size()){
            return true;
        }
        if(p1>=p.size() && s1<s.size()){
            return false;
        }
        if(dp[s1][p1]!=-1){
            return dp[s1][p1];
        }
        bool first_match = (s1<s.size()) && (s[s1]==p[p1] || p[p1]=='.');

        if(p1+1<p.size() && p[p1+1]=='*'){
            bool second = recurr(s1,p1+2,s,p) || (first_match && recurr(s1+1,p1,s,p));
            return dp[s1][p1] = second;
        }
        if(first_match){
            return dp[s1][p1] = recurr(s1+1,p1+1,s,p);
        }

        return dp[s1][p1] = false;
        
    }
    bool isMatch(string s, string p) {
        dp.assign(s.size()+1,vector<int>(p.size()+1,-1));
        return recurr(0,0,s,p);
    }
};
