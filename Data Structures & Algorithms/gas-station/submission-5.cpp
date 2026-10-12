class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int diff = 0;
        int res = 0;
        int curr = 0;
        int prev = 0;
        for(int i = 0; i<gas.size(); i++){
            curr+=gas[i]-cost[i];
           diff+=gas[i]-cost[i];
           if(curr<0){
                res = i+1;
                curr = 0;
           }
         
        }
      
        if(diff<0){
            
            return -1;
        }
        return res;
    }
};
