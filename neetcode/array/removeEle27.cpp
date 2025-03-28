#include<iostream>
#include<vector>

using namespace std;

// https://leetcode.com/problems/remove-element/description/
// Ans:Have a right pointer. traverse through the vector, if matched swap, curr element to the right pointer
// and decrement right pointer

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int r = nums.size() -1, i=0;
        while(i <= r) {
            if (nums[i] == val){
                swap(nums[i], nums[r]);
                r--;
            } else {
                i++;
            }
        }
        return r+1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}