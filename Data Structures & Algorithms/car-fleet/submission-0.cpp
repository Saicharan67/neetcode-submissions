class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        

        vector<pair<int,int>> cars;
        vector<double> st;

        for(int i = 0; i<position.size(); i++){

            cars.push_back({position[i],speed[i]});
        }

        sort(cars.begin(), cars.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.first > b.first;  // descending by position
        });
      
        for(auto x: cars){
            double time = (double)(target - x.first) / x.second;
            if(!st.empty()){
                if(st.back()>=time){
                    continue;
                }
            }
            st.push_back(time);
        }

        return st.size();
    }
};
