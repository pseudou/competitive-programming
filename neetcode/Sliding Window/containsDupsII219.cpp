#include <vector>
#include<map>

using namespace std;

// https://leetcode.com/problems/contains-duplicate-ii/
// ans: create a hash map that stores values for the window. This is a fixed window.
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> s;
        int i = 0, j = 1;
        s[nums[0]] =0;
        while (i < nums.size() && j< nums.size()) {
            if (j - i > k) {
                //cout << "debug1" << i <<" "<< j << endl;
                i++;
            }
            if (s.find(nums[j]) == s.end() || s[nums[j]] < i) {
                //cout << "debug2" << i <<" "<< j << endl;
                s[nums[j]] = j;
                j++;
            } else {
                return true;
            }
        }
        return false;
    }
};