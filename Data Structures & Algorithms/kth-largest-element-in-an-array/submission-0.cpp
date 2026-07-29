class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> mh;

        for(int i:nums){

            mh.push(i);
            if(mh.size()>k){
                mh.pop();
            }
        }

        return mh.top();
    }
};
