#include <iostream>
#include <string>

// https://leetcode.com/problems/valid-anagram/
// either sort and check or count chars in one string and substract from the other. if negative then no anagram
using namespace std;
class Solution {
public:
    bool isAna(string s, string p) {
        if (s.size() != p.size()) return false;

        vector<int> m(26);
        for (char c:s) {
            m[c -'a']++;
        }

        for (char c:p) {
            m[c-'a']--;
            if (m[c-'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution s = Solution();
    cout << s.isAna("isant", "anais");

}