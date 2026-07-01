class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";
        unordered_map<char,int> countT, countS;
        for (char c : t) {
            countT[c]++;
        }
        int have = 0;
        int need = countT.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;
        for(int r = 0; r<s.length();r++){

            countS[s[r]]++;
            if(countT.count(s[r])>0 && countT[s[r]]==countS[s[r]]){
                have++;
            }

            while(have==need){

                 if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }
                countS[s[l]]--;
                if(countT.count(s[l])>0 && countS[s[l]]<countT[s[l]]){
                    have--;
                }
                l++;

            }
        }
    return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
