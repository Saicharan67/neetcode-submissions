#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        unordered_map<char, vector<char>> mp;
        unordered_map<char, int> id;

        int n = words.size();
        for (const string& word : words) {
            for (char ch : word) {
                mp[ch]; // Ensures the character exists as a key in the adjacency list
                id[ch] = 0;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {

                int len = min(words[i].size(), words[j].size());
                for (int k = 0; k < len; k++) {

                    if (words[i].size() > words[j].size() && words[i].substr(0, words[j].size()) == words[j]) {
                        return ""; // Invalid order: longer word precedes its prefix
                    }
                    if (words[i][k] != words[j][k]) {
                       
                            mp[words[i][k]].push_back(words[j][k]);
                            id[words[j][k]]++;
                           
                      
                        break; // stop at first difference
                    }
                }
            }
        }

        deque<char> dq;
        vector<char> res;

        for (auto& [k, v] : id) {
            if (v == 0) {
                dq.push_back(k);
            }
        }

        while (!dq.empty()) {

            char temp = dq.front();
            dq.pop_front();
            res.push_back(temp);
         //   cout<<temp;

            for (auto ch : mp[temp]) {
                id[ch]--;
                if (id[ch] == 0) {
                    dq.push_back(ch);
                }
            }
        }

        if(res.size()!=id.size()){
            return "";
        }

        
        return string(res.begin(),res.end());
      
    }
};
