// <REDO>

// https://leetcode.com/problems/find-k-closest-elements/description/
// This is more like two pointer. l pointer  =0, r pointer end of arr. while loop until r - l == k
//

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - 1;
        while (r - l >= k) abs(arr[l] - x) > abs(arr[r] - x) ? ++l : --r;
        return vector<int>(arr.begin() + l, arr.begin() + r + 1);
    }
};