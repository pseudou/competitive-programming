#include<vector>
#include<iostream>

using namespace std;

// https://leetcode.com/problems/container-with-most-water/description/
// Ans: simple two pointer method. And greedy solution.

class Solution {
public:
    int maxArea(vector<int>& h) {
        int l=0, r= h.size()-1;
        int maxA = 0;
        while (l < r) {
            if (h[l] < h[r]) {
                maxA = max(maxA, h[l]* (r-l));
                l++;
            } else if(h[l] > h[r]) {
                maxA = max(maxA, h[r]* (r-l));
                r--;
            } else {
                maxA = max(maxA, h[r]* (r-l));
                l++;
            }
        }
        return maxA;
    }
};