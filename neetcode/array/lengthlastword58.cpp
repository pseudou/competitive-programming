#include<iostream>
#include<string>

using namespace std;

// https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lenLastWord(string s) {
        int len = 0;
        for (int i=s.size() -1; i>=0; i--) {
            if (s[i] == ' ' && len ==0) {
                continue;
            } else if (s[i] != ' ' ) {
                len++;
            } else if (s[i] == ' ' and len != 0) {
                return len;
            }
        }
        return len;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}