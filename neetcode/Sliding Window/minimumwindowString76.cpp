#include<string>
#include<vector>

using namespace std;
// <REDO>

// https://leetcode.com/problems/minimum-window-substring/description/
// Ans:

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> charCount(128, 0); // Frequency map for characters in t
        for (char c : t) {
            charCount[c]++; // Store required character frequencies
        }

        int requiredChars = t.size(); // Number of characters we need to match
        int left = 0, right = 0; // Two pointers for the sliding window
        int minLength = INT_MAX, startIndex = 0; // Track minimum window size and start index

        while (right < s.size()) {
            // Expand the window by moving `right`
            if (charCount[s[right]] > 0) {
                requiredChars--; // A required character is found
            }
            charCount[s[right]]--; // Decrement frequency in map
            right++;

            // Try to shrink the window from `left` if all required characters are matched
            while (requiredChars == 0) {
                // Update minimum window if the current window is smaller
                if (right - left < minLength) {
                    minLength = right - left;
                    startIndex = left;
                }

                // Shrink the window by moving `left`
                charCount[s[left]]++; // Restore the frequency of `s[left]`
                if (charCount[s[left]] > 0) {
                    requiredChars++; // A required character is now missing
                }
                left++;
            }
        }

        return minLength == INT_MAX ? "" : s.substr(startIndex, minLength);
    }
};
