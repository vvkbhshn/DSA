//problem link: https://leetcode.com/problems/design-twitter/

struct tweet{
    int time,arrIndex,userId;
    tweet(int a, int b, int c){
        time=a; arrIndex=b; userId=c;
    }
};

class myCmp{
    public:
    bool operator()(tweet &a, tweet &b){
        return a.time<b.time;
    }
};

class Twitter {
private:
    int currTime;
    unordered_map<int,deque<pair<int,int>>> tweets;
    unordered_map<int,unordered_set<int>> following;
public:       
    Twitter() {
        currTime=1;    
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({currTime,tweetId});
        if(tweets[userId].size()>10) tweets[userId].pop_front();
        currTime++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<tweet,vector<tweet>,myCmp>pq;
        for(auto followee:following[userId]){
            if(tweets.find(followee)==tweets.end()) continue;
            int n=tweets[followee].size();
            pq.push(tweet(tweets[followee][n-1].first,n-1,followee));
        }
        if(tweets.find(userId)!=tweets.end()){
            int n=tweets[userId].size();
            pq.push(tweet(tweets[userId][n-1].first,n-1,userId));
        } 
        while(!pq.empty() && res.size()<10){
            auto item=pq.top();
            pq.pop();
            res.push_back(tweets[item.userId][item.arrIndex].second);
            if(item.arrIndex>0) pq.push({tweets[item.userId][item.arrIndex-1].first,item.arrIndex-1,item.userId});
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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


// Method-2: NeetCode

// /*
//     Design Twitter: post tweets, follow/unfollow, see recent tweets

//     Maintain user -> tweet pairs & hash map {user -> ppl they follow}

//     Time: O(n)
//     Space: O(n)
// */

// class Twitter {
// public:
//     Twitter() {
        
//     }
    
//     void postTweet(int userId, int tweetId) {
//         posts.push_back({userId, tweetId});
//     }
    
//     vector<int> getNewsFeed(int userId) {
//         // 10 tweets
//         int count = 10;
//         vector<int> result;
        
//         // since postTweet pushes to the back, looping from back gets most recent
//         for (int i = posts.size() - 1; i >= 0; i--) {
//             if (count == 0) {
//                 break;
//             }
            
//             int followingId = posts[i].first;
//             int tweetId = posts[i].second;
//             unordered_set<int> following = followMap[userId];
//             // add to result if they're following them or it's a tweet from themself
//             if (following.find(followingId) != following.end() || followingId == userId) {
//                 result.push_back(tweetId);
//                 count--;
//             }
//         }
        
//         return result;
//     }
    
//     void follow(int followerId, int followeeId) {
//         followMap[followerId].insert(followeeId);
//     }
    
//     void unfollow(int followerId, int followeeId) {
//         followMap[followerId].erase(followeeId);
//     }
// private:
//     // pairs: [user, tweet]
//     vector<pair<int, int>> posts;
//     // hash map: {user -> people they follow}
//     unordered_map<int, unordered_set<int>> followMap;
// };