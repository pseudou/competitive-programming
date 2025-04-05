#include<vector>

using namespace std;

// https://leetcode.com/problems/binary-search/

class Solution {
public:

    int binarySearch(vector<int>& a, int t, int l , int r) {
        if (l == r && t == a[l]) return l;
        if (l == r) return -1;
        int mid = (l+r) / 2;

        if (t > a[mid]) {
            return binarySearch(a, t, mid + 1, r);
        } else {
            return binarySearch(a, t , l, mid);
        }

    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size()-1);
    }
};