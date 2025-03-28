#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;


// https://leetcode.com/problems/sort-colors/
// Ans: 3 pointers, start pointer, end pointer and traverse point i.
// if i == 0, swap start and i, increment both (since swapped element is already traversed)
// if i == 2, swap end and i, only decrement end pointer cuz swapped element is not traversed.
// else increment i

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z = 0, t = nums.size() - 1, i = 0;

        while (i <= t) {
            if (nums[i] == 0) {
                swap(nums[i], nums[z]);
                z++;
                i++;
            } 
            else if (nums[i] == 2) {
                swap(nums[i], nums[t]);
                t--;
            } 
            else {
                i++;
            }
        }
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}