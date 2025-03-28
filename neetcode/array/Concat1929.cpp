#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/concatenation-of-array/
// ans: push_back the elements that is being traversed from i =0 to n-1

class Concat1929 {
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
    Concat1929 s = Concat1929();
    vector<int> nums = {1,3,2,1};
    vector<int> ans = s.getConcatenation(nums);
    for (int i=0; i< ans.size();i++) {
        cout << ans[i] << " " ;
    }
}

