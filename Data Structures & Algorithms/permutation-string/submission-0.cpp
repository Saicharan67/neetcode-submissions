class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int l1 = s1.length();
        int l2 = s2.length();

        vector<int> c1(26,0);
        vector<int> c2(26,0);

        for(auto s:s1){

            c1[s-'a']++;
        }

        for(int i=0;i<l2;i++){

            c2[s2[i]-'a']++;
            if(i>=l1){

                c2[s2[i-l1]-'a']--;
            }
            if(c1==c2){
                return true;
            }
        }

        return false;


        
    }
};
