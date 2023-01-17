class Twitter {

public:
    unordered_map<int,unordered_set<int>>friends;
    int cnt;
    priority_queue<vector<int>>newsfeed;
    Twitter() {
        cnt=0;
        newsfeed=priority_queue<vector<int>>();
        friends.clear();
    }
    void postTweet(int userId, int tweetId) {
        newsfeed.push({cnt++,tweetId,userId});
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>>pq=this->newsfeed;
        vector<int>ans;
        int i=0;
        while(i<10 and !pq.empty()){
            auto tp=pq.top();pq.pop();
            if(tp[2]==userId || friends[userId].count(tp[2])){
                ans.push_back(tp[1]);
                i++;
            }
        }
        return ans;
    }
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */