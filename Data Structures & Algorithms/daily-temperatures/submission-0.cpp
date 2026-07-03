class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {

        vector<pair<int,int>> st;
        vector<int> res(t.size(),0);

        for(int i = 0 ; i<t.size() ; i++){

           

                while(!st.empty() && st.back().first < t[i]){
                    res[st.back().second] = i-st.back().second;
                    st.pop_back();
                }
                
            
            st.push_back({t[i],i});
        }
        return res;
    }
};
