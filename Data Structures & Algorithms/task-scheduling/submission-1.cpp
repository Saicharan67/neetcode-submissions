class Solution {    
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char,int> mp;

        for(char t:tasks){
            mp[t]+=1;
        }

        // NOTE: pair<int,char> means first=frequency, second=task
        priority_queue<pair<int,char>> pq;
        deque<pair<int,char>> dq;

        for(auto it:mp){
            pq.push({it.second,it.first}); // corrected order: freq first, char second
        }

        int t = 0;
        while(!pq.empty() || !dq.empty()){

            cout << "\n--- Cycle " << t << " ---\n";

            // Print PQ
            {
                priority_queue<pair<int,char>> tmp = pq;
                cout << "PQ: ";
                while(!tmp.empty()){
                    auto p = tmp.top(); tmp.pop();
                    cout << "(" << p.second << "," << p.first << ") ";
                }
                cout << "\n";
            }

            // Print DQ
            {
                cout << "DQ: ";
                for(auto &p : dq){
                    cout << "(" << p.second << ",ready@" << p.first << ") ";
                }
                cout << "\n";
            }

            if(!pq.empty()){
                auto x = pq.top();
                pq.pop();
                t+=1;
                mp[x.second]-=1;
                cout << "Executing task " << x.second << " at time " << t << "\n";
                if(mp[x.second] > 0) {
                    dq.push_back({t+n, x.second});
                }
            } 
            
            if(!dq.empty()){
               auto y = dq.front(); 
                if(t>=y.first){
                    pq.push({mp[y.second], y.second});
                    dq.pop_front();
                }else{
                    if(pq.empty()){
                        t = max(t, y.first); // jump to when it's ready
                        cout << "Cooldown wait until " << t << "\n";
                        pq.push({mp[y.second], y.second});
                        dq.pop_front();
                    }
                }
               
                
            }

          
        }

        return t;
    }
};