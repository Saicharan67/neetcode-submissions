class MinStack {
public:
    vector<int> st;
    vector<int> minst;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
        if(minst.size()>0){
             minst.push_back(min(minst.back(),val));
        }else{
             minst.push_back(val);
        }
       
    }
    
    void pop() {
        st.pop_back();
        minst.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minst.back();
    }
};
