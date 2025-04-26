
// https://leetcode.com/problems/subsets/description/
// simple recursion.

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> currset;
    void subs(int i, vector<int>& nums) {
        if (i == nums.size()) {
            ans.push_back(currset);
            return;
        }
        subs(i+1, nums);
        currset.push_back(nums[i]);
        subs(i+1, nums);
        currset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        currset.clear();
        subs(0, nums);
        return ans;
    }
};