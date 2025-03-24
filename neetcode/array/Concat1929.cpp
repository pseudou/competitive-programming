// https://leetcode.com/problems/concatenation-of-array/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i<n; i++) {
            nums.push_back(nums[i]);
        }
        return nums;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution s = Solution();
    vector<int> nums = {1,3,2,1};
    vector<int> ans = s.getConcatenation(nums);
    for (int i=0; i< ans.size();i++) {
        cout << ans[i] << " " ;
    }
}

