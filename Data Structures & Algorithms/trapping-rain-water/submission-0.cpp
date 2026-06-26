class Solution {
public:
    int trap(vector<int>& h) {

        int n = h.size();
        if(n<3){
            return 0;
        }
        
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);

        for(int i = 0; i<n ;i++){

            if(i>0){
                prefix[i]=max(h[i],prefix[i-1]);
                suffix[n-i-1]=max(h[n-i-1],suffix[n-i]);
            }else{
                prefix[i]=h[i];
                suffix[n-i-1]=h[n-i-1];
            }
        }
        int res = 0;
        for(int i=0;i<n;i++){

            res+=min(prefix[i],suffix[i])-h[i];

        }

        return res;
        
    }
};
