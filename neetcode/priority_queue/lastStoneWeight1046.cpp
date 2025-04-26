
// https://leetcode.com/problems/last-stone-weight/description/
// Ans; simple priority queue.

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int i=0; i< stones.size(); i++) {
            pq.push(stones[i]);
        }

        while (pq.size() != 1) {
            int s1 = pq.top();
            pq.pop();
            int s2= pq.top();
            pq.pop();
            pq.push(abs(s1 - s2));
        }

        return pq.top();

    }
};