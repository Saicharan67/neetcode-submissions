class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int> dict = {};
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        while(i<n){

            if(dict.find(s[i])!=dict.end() && dict[s[i]]>=j){
      
                j = dict[s[i]] +1;
                dict[s[i]] = i;
                i+=1;

            }else{

                dict[s[i]]=i;
                i+=1;
                ans = max(ans,i-j);
                
            }


        }
        
        return ans;
        
    }
};
