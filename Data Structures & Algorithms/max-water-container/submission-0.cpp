class Solution {
public:
    int maxArea(vector<int>& h) {

        int l = 0;
        int r = h.size()-1;
        int res = (r-l)*min(h[l],h[r]);

        while(l<r){

            if(h[l]<h[r]){
                l++;
            }else{
                r--;
            }
            res = max(res,(r-l)*min(h[l],h[r]));

        }
        return res;
        
    }
};
