class Solution {
public:
    bool isPalindrome(string s) {

        string res = "";

        for(char c:s){

            if(isalnum(c)){

                if(isdigit(c)){
                    res+=c;
                }else{
                    res+=tolower(c);
                }
            }
        }

        int l = 0;
        int r = res.length()-1;

        while(l<r){

            if(res[l]!=res[r]){
                return false;
            }
            l++;
            r--;
        }

        return true;
        
    }
};
