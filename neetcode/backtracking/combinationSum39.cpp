// https://leetcode.com/problems/combination-sum/

// simple backtracking. Insert until currsum > target or i == nums.size().


class Solution {
public:

    vector<vector<int>> ans;
    vector<int> currset;
    void subs(int i, vector<int>& nums, int target, int currsum) {
        if (target == currsum) {
            ans.push_back(currset);
            return;
        }
        if (target < currsum || i == nums.size()) {
            return;
        }
        currset.push_back(nums[i]);
        subs(i, nums, target, currsum + nums[i]);
        currset.pop_back();
        subs(i+1, nums, target, currsum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        currset.clear();
        subs(0, candidates, target, 0);

        return ans;
    }
};