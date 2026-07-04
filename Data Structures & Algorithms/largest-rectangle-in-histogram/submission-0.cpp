class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        

        int res = 0;

        vector<pair<int,int>> st;

        for(int i = 0;i<h.size();i++){

            if(st.empty()){

                st.push_back({i,h[i]});
            }else{
                int x = i;
                while(!st.empty() && st.back().second > h[i]){
                    x = st.back().first;
                    res = max(res, (i-st.back().first)*st.back().second);
                    st.pop_back();
                
                }
                st.push_back({x, h[i]});
            }
        }
        int t = h.size();
        for(auto p : st){

                res = max(res, (t-p.first)*p.second);
        }

        return res;
    }
};
