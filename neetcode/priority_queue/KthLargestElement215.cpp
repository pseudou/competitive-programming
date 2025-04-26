
// https://leetcode.com/problems/kth-largest-element-in-an-array/description/
// Ans; simple min Heap implementation.

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minh;
        int i = 0;
        for (i=0; i < k; i++) {
            minh.push(nums[i]);
        }
        while (i < nums.size()) {
            if (nums[i] > minh.top()) {
                minh.push(nums[i]);
                minh.pop();
            }
            i++;
        }
        return minh.top();
    }
};