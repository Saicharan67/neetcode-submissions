class Solution {
public:
    int perpiletime(vector<int>& piles ,int eatSpeed){

        int res = 0;
        for(int p : piles){

            res += (p + eatSpeed - 1) / eatSpeed;
        }
        return res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int mid = 0;
        while(l<r){

            mid = l + (r-l)/2;

            if(perpiletime(piles,mid)>h){

                l = mid+1;
            }else{

                r = mid;
            }

        }

        return l;

    }
};
