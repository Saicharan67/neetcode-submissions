class Solution {
public:
    double stub(vector<int> p){
        return sqrt(p[0]*p[0] + p[1]*p[1]);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         priority_queue<pair<double,int>> pq;

         for(int i = 0; i<points.size(); i++){
            double b = stub(points[i]);
             cout<<b;
            if(pq.size()>=k){
                
                
                
                if(b<pq.top().first){
                    pq.pop();
                    pq.push({b,i});
                }
            }else{
                pq.push({b,i});
            }
         }
         
         vector<vector<int>> res;

         while(pq.size()){

            auto it = pq.top();
            pq.pop();
            res.push_back(points[it.second]);
         }

         return res;

        
    }
};
