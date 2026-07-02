class Solution {
public:
    bool isValid(string s) {
        

        vector<char> stack;
       unordered_map<char, char> m = {
    {'[', ']'},
    {'{', '}'},
    {'(', ')'}
};

        for(auto c:s){

            if(m.count(c)>0){
                stack.push_back(c);
            }else{
                if(stack.empty()){
                    return false;
                }
                char temp = stack.back();
                stack.pop_back();
                if(m[temp]!=c){
                    return false;
                }
            }

        }

        return stack.size()==0?true:false;
    }
};
