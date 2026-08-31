class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        vector<string> temp;
        temp.push_back(beginWord);
        for(auto st:wordList){
            temp.push_back(st);
        }

        unordered_map<int,vector<int>> mp;
        int wordL = beginWord.length();
        for(int i = 0; i < temp.size()-1; i++){
            for(int j = i+1; j<temp.size(); j++){
                int tc = 0;
                for(int k = 0; k<wordL; k++){
                        
                        if(temp[i][k]!=temp[j][k]){
                            tc++;
                        }
                        
                }
                if(tc==1){
                    mp[i].push_back(j);
                    mp[j].push_back(i);                
                }
            }
        }

        vector<int> v(temp.size(),0);
        deque<int> dq;
        dq.push_back(0);

        v[0] = 0;
        int level = 1;

        while(dq.size()){
            int ds = dq.size();

            for(int i = 0; i<ds; i++){
                int t = dq.front();
                
                dq.pop_front();
                for(auto z:mp[t]){
                        if(!v[z]){
                            v[z] = level;
                            dq.push_back(z);
                        }
                }
            }
            level++;
        }

        auto it = find(temp.begin(), temp.end(), endWord);

        if (it != temp.end()) {
            if(v[it - temp.begin()]){
                return v[it - temp.begin()]+1;
            }else{
                return 0;
            }
        } else {
            return 0;
        }

        
        
    }
};
