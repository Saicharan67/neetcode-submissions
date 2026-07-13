class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int avg = 0;
        int res = 0;
        for(int i = 0; i<k; i++){
            avg+=arr[i];
        }
        avg = avg/k;
        if(avg>=threshold){
            res+=1;
        }
        for(int i = k ; i< arr.size(); i++){

            avg -= arr[i-k]/k;
            avg += arr[i]/k;
            if(avg>=threshold){
            res+=1;
            }
        }

        return res;
    }
};