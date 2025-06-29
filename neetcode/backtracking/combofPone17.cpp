class Solution {
public:
    unordered_map<char, vector<char>> m = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}},
    };
    vector<string> ans;
    void comb(string digits, int curr, string currs) {
        if (curr == digits.size()) {ans.push_back(currs); return;}
        for (int i = 0; i < m[digits[curr]].size(); i++) {
            comb(digits, curr + 1, currs + m[digits[curr]][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        ans.clear();
        if (digits == "") return ans;
        comb(digits, 0, "");
        return ans;
    }
};