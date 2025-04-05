
//https://leetcode.com/problems/minimum-size-subarray-sum/description/
// Ans; create a window. keep incrementing right until sum < target. When sum >= target, create another while
// loop to increment left pointer until sum < target.

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r =0, csum=0, minl =INT_MAX ;

        while (r <nums.size()) {
            csum += nums[r];

            while (csum >= target) {
                minl = min(minl, r - l + 1);
                csum -= nums[l];
                l++;
            }
            r++;
        }
        return minl == INT_MAX ? 0: minl;
    }
};