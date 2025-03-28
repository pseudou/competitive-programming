#include<unordered_map>
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

// H https://leetcode.com/problems/top-k-frequent-elements/description/
// first count the ints in the vector. then create a min heap that removes least occurring element
// when min heap size is k+1
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minh;
        for (int i:nums) {
            m[i]++;
        }

        for (auto [key, val]: m) {
            minh.push({val, key});

            if (minh.size() > k) {
                minh.pop();
            }

        }
        vector<int> ans;
        while (minh.size() != 0) {
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;

    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}