class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<int> dist(n,INT_MAX);
       

        dist[src]=0;
   
        for(int i = 0; i<=k; i++){
            vector<int> newDist = dist;
            for(auto &v:flights){
                int s = v[0];
                int d = v[1];
                int c = v[2];
                if((dist[s]!=INT_MAX) && dist[s]+c<newDist[d]){
                   
                        newDist[d] = dist[s]+c;
                        
                }
              
            }
            dist = newDist;
        }

        return dist[dst]==INT_MAX?-1:dist[dst];
        
    }
};
