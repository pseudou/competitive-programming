#include<iostream>
#include<string>

using namespace std;

// M https://leetcode.com/problems/permutation-in-string/description/

// Ans: first keep a map to count the chars in s1. next interate through s2. if you don't find the char in map
// the go next. If you do, create a window starting from here. keep incrementing j if you find the char in map
// and simultaneously dicrement char count in map. If not found in map, move the left pointer to the right and
// increment the character count. If lets say i ==j then no solution exists, exit from sliding window and do the usual
// process.
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mc;

        for (char c: s1) {
            mc[c]++;
        }

        int i = 0, j = 0;
        while (i < s2.size() && j <s2.size()) {
            if (mc.find(s2[j]) == mc.end()) {
                j++;
            } else {
                i =j;
                while ( i < s2.size() && j < s2.size()) {
                    
                    if (mc.find(s2[j]) != mc.end() && mc[s2[j]] != 0) {
                        mc[s2[j]]--;
                        j++;
                        if (j - i  == s1.size()) return true;
                    } else if (i < j) {
                        mc[s2[i]]++;
                        i++;
                    }
                    else {
                        j++;
                        break;
                    }
                }
            }

        }
        return false;

    }
};