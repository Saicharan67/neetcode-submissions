class Solution {
public:
    vector<vector<int>> dp;
    int recurr(int s1, int s2, string t1, string t2){
        if(s1>=t1.size() && s2>=t2.size()){
            return 0;
        }
        if(s1>=t1.size()){
            return t2.size()-s2;
        }
        if(s2>=t2.size()){
            return t1.size()-s1;
        }
        if(dp[s1][s2]!=-1){
            return dp[s1][s2];
        }

        if(t1.substr(s1,1)==t2.substr(s2,1)){
            return  dp[s1][s2] = recurr(s1+1,s2+1,t1,t2);
        }else{
           
            return  dp[s1][s2] = 1+min(min(recurr(s1+1,s2,t1,t2),recurr(s1,s2+1,t1,t2)),recurr(s1+1,s2+1,t1,t2));
        }
    }
    int minDistance(string text1, string text2) {
        dp.assign(text1.size()+1,vector<int>(text2.size()+1,-1));
        return recurr(0,0,text1,text2);
        
    
    }
};
