#include <iostream>
#include <vector>

using namespace std;

// E https://leetcode.com/problems/majority-element/description/
// Ans; keep a frequency counter and selected num, if the current num is equal to current num, increment freq,
// if not decrement. If freq reaches 0, then replace it with current num.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0, num = 0;

        for (int i:nums) {
            if (freq == 0 ) {
                num = i;
            }
            freq += num == i ? 1:-1;
        }
        return num;

        // unordered_map<int,int> m;

        // for (int i:nums) {
        //     m[i]++;
        //     if (m[i] > floor(nums.size()/2)) {
        //         return i;
        //     }
        // }
        // return 0;
    }
};