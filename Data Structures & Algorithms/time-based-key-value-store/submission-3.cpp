class TimeMap {
public:
 unordered_map<string,vector<pair<string,int>>> ds;
    TimeMap() {
        
       
    }
    
    void set(string key, string value, int timestamp) {

        ds[key].push_back({value,timestamp});
        
    }
    
    string get(string key, int timestamp) { 

        

        auto arr = ds[key];

        if(ds[key].empty()){
            return "";
        }

        int l = 0;
        int r = arr.size()-1;

        while(l<r){


            int mid = l + (r-l+1)/2;


            if(arr[mid].second<=timestamp){

                l = mid;
            }else{
                r = mid - 1;
            }
        }

        return timestamp>=arr[l].second?arr[l].first:"";
        
    }
};
