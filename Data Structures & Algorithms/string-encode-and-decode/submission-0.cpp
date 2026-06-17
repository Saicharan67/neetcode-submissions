#include <cstring>
class Solution {
public:

    string encode(vector<string>& strs) {

        string encode ="";

        for(auto s: strs){

            int len = s.length();
            encode.append(reinterpret_cast<char*>(&len),sizeof(len));
            encode += s;
        }
        return encode;

    }

    vector<string> decode(string s) {

        vector<string> res;
        size_t i = 0;
        while(i<s.length()){
            int len;

            memcpy(&len,&s[i],sizeof(len));
            i+=sizeof(len);
            string temp = s.substr(i,len);
            i+=len;
            res.push_back(temp);
        }
        return res;


    }
};
