class Solution {
public:
    bool recurr(string s, int sidx, int widx, vector<string>& wordDict){
        if(sidx>=s.size()){
            return true;
        }
        if(widx>=wordDict.size()){
            return false;
        }

        int currlen = wordDict[widx].size();
        string sub = s.substr(sidx,currlen);
        bool a = false;
        bool b = false;
        if(sub==wordDict[widx]){
            a = recurr(s,sidx+currlen,0,wordDict);
        }

        b = recurr(s,sidx,widx+1,wordDict);

        return (a || b);

    }
     bool recurr(string s, int sidx, vector<string>& wordDict, vector<int>& memo){
        if(sidx>=s.size()){
            return true;
        }
        if (memo[sidx] != -1) {
            return memo[sidx];
        }
        for(auto s1:wordDict){
            int currlen = s1.size();
            string sub = s.substr(sidx,currlen);
            if(sidx + currlen <= s.size() && sub==s1){
                if(recurr(s,sidx+currlen,wordDict,memo)){
                    return memo[sidx]=1;
                }
            }
        }

       return memo[sidx] = 0;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> memo(n, -1);
        
        return recurr(s, 0, wordDict, memo);
    }
};
