#include<vector>
#include<iostream>

// https://leetcode.com/problems/pascals-triangle/description/
// Ans: normal pascals triangle, keep a track of previous array.

using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return {{1}};
        if (numRows == 2) return {{1}, {1, 1}};
        vector<vector<int>> ans = {{1}, {1,1}};
        vector<int> prevRow = {1,1}, currRow;

        while(numRows > 2) {
            currRow = {1};
            for (int i=1; i<prevRow.size();i++) {
                currRow.push_back(prevRow[i-1] + prevRow[i]);
            }
            currRow.push_back(1);
            prevRow = currRow;
            ans.push_back(currRow);
            numRows--;
        }

        return ans;

    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}