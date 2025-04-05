

// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
// binary search. find mid = low + high / 2. check if left side follows normal sorted. if it does
// then check if target exists between them, if yes, then choose left. if not choose right.
// if left side is not sorted. then check if target is present between mid and right, if yes, then choose right
// if not then choose left.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};