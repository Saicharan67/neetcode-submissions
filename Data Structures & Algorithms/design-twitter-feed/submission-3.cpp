class Twitter {
public:
 unordered_map<int,vector<pair<int,int>>> twts;
        unordered_map<int,set<int>> flws;
        int timer=0;
    Twitter() {
       
        
    }
    
    void postTweet(int userId, int tweetId) {
        twts[userId].push_back({timer++,tweetId});
        flws[userId].insert(userId);
        
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > mh;
        for(int usr:flws[userId]){

            for(auto twt: twts[usr]){

                mh.push(twt);
                if(mh.size()>10){
                    mh.pop();
                }
            }

        }

        vector<int> res;
        while(mh.size()){
            res.push_back(mh.top().second);
            mh.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        flws[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
           if(followerId!=followeeId){
       
        flws[followerId].erase(followeeId);
        }
       
    }
};
