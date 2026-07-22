class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int gk = 0;
    KthLargest(int k, vector<int>& nums) {
        gk = k;
        for(auto n:nums){

            if(pq.size()>=k){
                if(n>pq.top()){

                
                    pq.pop();
                    pq.push(n);
                }
                 
            }else{
                  pq.push(n);
            }
          
        }
    }
    
    int add(int val) {
        
       if(pq.size()>=gk){
                if(val>pq.top()){

                
                    pq.pop();
                    pq.push(val);
                }
                 
            }else{
                  pq.push(val);
            }
        return pq.top();
        

    }
};
