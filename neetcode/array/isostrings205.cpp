#include<string>
#include<iostream>

using namespace std;

// https://leetcode.com/problems/isomorphic-strings/description/
// have two maps, that maps from string1 chars to string 2 chars and vice versa. if didn't find, add them
// if found then verify the mapping is as expected.

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char,char> m;
        unordered_map<char,char> rm;
        for (int i=0; i < s.size(); i++) {
            if (m.find(s[i]) == m.end() && rm.find(t[i]) == rm.end()) {
                m[s[i]] = t[i];
                rm[t[i]] = s[i];
            } else {
                if (t[i] != m[s[i]] && rm[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

}