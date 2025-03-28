#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

// https://leetcode.com/problems/longest-common-prefix/
// Sort the vector, it will become lexically sorted, compare the ends of the vector to find common prefix.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int i=0, j=0;
        string ans = "";
        while(i<strs[0].size() && j < strs[strs.size()-1].size()) {
            if (strs[0][i] == strs[strs.size()-1][j]) {
                ans += strs[0][i];
                i++;
                j++;
            } else {
                return ans;
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

}