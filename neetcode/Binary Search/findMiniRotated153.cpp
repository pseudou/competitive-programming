
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

// Ans: binary search. mid = ceil (l+r/2). if mid < mid - 1 then return mid cuz that is minimum.
// if not check if l > r and l < mid, if yes the minimum is present in the right side else
// it is present in the left side.

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l =0, r = nums.size() -1, mid;

        while (l <= r) {
            mid = (int) ceil((float)(l+r)/2);
            //cout << l << " " << mid << " " << r << endl;

            if ( l == r || nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }
            if (nums[l] > nums[r] && nums[l] < nums[mid]) {
                l = mid + 1;
            } else {
                r = mid -1;
            }
        }
        return -1;
        
    }
};