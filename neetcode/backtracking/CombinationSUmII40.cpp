
// https://leetcode.com/problems/combination-sum-ii/
// First sort the array.
// recursive, so push the curr iterator val, recursive call fn argument as next iterator
// pop the val. After popping, while loop and increment iterator until the next element is
// not equal to current popped element.

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
        subs(i+1, nums, target, currsum + nums[i]);
        currset.pop_back();
        while(i != nums.size()-1 && nums[i] == nums[i+1]) {
            i++;
        }
        subs(i+1, nums, target, currsum);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        ans.clear();
        currset.clear();
        subs(0, candidates, target, 0);
        return ans;
    }
};