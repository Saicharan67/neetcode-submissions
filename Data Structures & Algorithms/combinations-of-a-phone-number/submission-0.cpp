#include <iostream>


class Solution {
public:
    string gs = "";
    vector<string> dtc = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};
    void backtrack(vector<string> &res, string &s, int idx, int len){

        if(idx==len && s!=""){
            res.push_back(s);
        }
        if(idx<len){
        string temp = dtc[stoi(gs.substr(idx,1))];
        for(int i = 0; i<temp.length(); i++){
            s+= temp.substr(i,1);
            backtrack(res,s,idx+1,len);
            s.pop_back();
        }
        }
    }
    vector<string> letterCombinations(string digits) {
        gs = digits;
        vector<string> res;
        string s = "";
        backtrack(res,s,0,digits.length());

        return res;
        
    }
};
