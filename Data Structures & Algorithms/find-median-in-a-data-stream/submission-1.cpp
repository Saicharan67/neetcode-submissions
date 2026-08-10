class MedianFinder {
public:
priority_queue<int> l;
priority_queue<int,vector<int>,greater<int>> r;
    MedianFinder() {
        
    }
    
    void addNum(int num) {

        if(l.empty()){
            l.push(num);
        }else{
            if(l.top()>num){
                l.push(num);
            }else{
                r.push(num);
            }
        }
        
        if(l.size() > r.size() + 1){

            r.push(l.top());
            l.pop();
        }else if(r.size() > l.size()+1){
            l.push(r.top());
            r.pop();
        }
        
    }
    
    double findMedian() {
        if(l.size()==r.size()){

           double median = (l.top() / 2.0 + r.top() / 2.0);
           return median;

        }else if(l.size()>r.size()){
            return l.top();
        }else{
            return r.top();
        }
        
    }
};
