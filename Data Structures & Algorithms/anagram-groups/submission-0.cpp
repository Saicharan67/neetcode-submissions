class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string,vector<string>> result;

        for(auto s:strs){

            vector<int> count(26,0);

            for(char c:s){

                count[c-'a']++;
            }

            string k = to_string(count[0]);

            for(int i=1;i<26;i++){

                k += ','+to_string(count[i]);
            }

            result[k].push_back(s);
        }

        vector<vector<string>> res;

        for(const auto& p : result){

            res.push_back(p.second);
        }
        return res;
        
    }
};
