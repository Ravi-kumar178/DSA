
class Twitter {
struct Tweet{
    int tweetId;
    int time;

    Tweet(int id, int t){
        tweetId = id;
        time = t;
    }
};

int Time = 0;
//map, userId->Tweet
unordered_map<int,vector<Tweet>>tweets;
//map, userId->userId to his followings
unordered_map<int,unordered_set<int>>following; 
class Compare{
    public:
    bool operator()(const Tweet& a, const Tweet& b){
        return a.time > b.time;
    }
};
public:
    Twitter() {
        Time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(Tweet(tweetId,Time));
        Time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet,vector<Tweet>,Compare>minHeap;

        //add my tweets
        if(tweets.find(userId) != tweets.end()){
            auto myTweets = tweets[userId];
            for(auto tweet: myTweets){
                minHeap.push(tweet);
                if(minHeap.size() > 10) minHeap.pop();
            }
        }

        //add my following tweets
        if(following.find(userId) != following.end()){
            auto myFollowings = following[userId];
            for(auto followeeId: myFollowings){
                if(tweets.find(followeeId) != tweets.end()){
                    auto followingTweets = tweets[followeeId];
                    for(auto tweet: followingTweets){
                        minHeap.push(tweet);
                        if(minHeap.size() > 10) minHeap.pop();
                    }
                }
            }
        }

        vector<int>ans;
        while(!minHeap.empty()){
            auto [tweetId, time] = minHeap.top(); minHeap.pop();
            ans.push_back(tweetId);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        following[followerId].insert(followeeId);
        return;
    }
    
    void unfollow(int followerId, int followeeId) {
        if(following.find(followerId) != following.end()){
            following[followerId].erase(followeeId);
        }
        return;
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