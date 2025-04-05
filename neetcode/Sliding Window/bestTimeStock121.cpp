#include<vector>
#include<iostream>

// E https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
// sliding window. have a lp and rp for the window, start with 0 and 0. slide right pointer if r > l.
// if l > r then reset window to r and start sliding r pointer.

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int l=0, r=0, maxp = 0;

        while(l < p.size() && r < p.size()) {
            maxp = max(p[r] - p[l], maxp);
            if (p[r] > p[l]) {
                r++;
            } else {
                l = r;
                r++;
            }
        }

        return maxp;
    }
};