// https://leetcode.com/problems/design-twitter/description/

// Keep a track of the followers list and tweet list of a user.

class Twitter {
public:
    unordered_map<int, deque<pair<int,int>>> userMap;
    unordered_map<int, unordered_set<int>> fMap;
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        userMap[userId].push_back({time, tweetId});
        while (userMap[userId].size() > 10) {
            userMap[userId].pop_front();
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        time++;
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        fMap[userId].insert(userId);

        for (int followee:fMap[userId]) {
            int n= userMap[followee].size();
            int i = max(0, n - 10);
            for (; i < userMap[followee].size(); i++) {
                pq.push(userMap[followee][i]);
            }
        }
        int count = 10;
        vector<int> ans;
        while(!pq.empty() && count != 0) {
            ans.push_back(pq.top().second);
            pq.pop();
            count--;
        }
        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        time++;
        fMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        time++;
        fMap[followerId].erase(followeeId);
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