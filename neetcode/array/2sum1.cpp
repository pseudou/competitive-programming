#include<vector>
#include<iostream>

using namespace std;

// https://leetcode.com/problems/two-sum/description/
// create a hash set. check if target - current is present in hash set, if yes return index, if no,
// store the current in hash set
class Solution {
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> s;

        for (int i=0;i< nums.size();i++) {
            auto it = s.find(target - nums[i]);
            if ( it == s.end()) {
                s[nums[i]] = i;
            } else {
                return vector<int> {it->second, i};
            }
        }

        return vector<int> {};
    }
};

int main() {
    return 0;
}