#include <iostream>
#include <map>

using namespace std;

// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// keep a hash map with key as char and value as index. left pointer  = 0 and right pointer = 1.
// keep incrementing right pointer and keep adding to the hash map. If you find a char that is already there
// then point the left pointer to the already inserted repeated char + 1 and change the map to the new repeated
// index. But if lets the repeated char is left of the left pointer, that means that ideally it should have
// been removed. So update char with the correct index.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        int l = 0, r = 1, maxl =1;
        unordered_map<char, int> m;
        m[s[l]] = l;

        while (l < s.size() && r < s.size()) {
            if (m.find(s[r]) == m.end() || m[s[r]] < l) {
                m[s[r]] = r;
            } else {
                l = m[s[r]] + 1;
                m[s[r]] = r;
            }
            maxl = max(maxl, r - l + 1);
            r++;
        }
        return maxl;
    }
};