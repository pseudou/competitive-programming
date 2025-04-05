#include <string>

using namespace std;
// https://leetcode.com/problems/valid-palindrome/
// two pointer method, remove all non alpha numeric characters!
class Solution {
public:
    bool isPalindrome(string s) {
        string cleans;
        for (char c:s) {
            c = tolower(c);
            if ((c >= 'a' && c <='z')||(c>='0' && c<='9')) {
                cleans += c;;
            }
            
        }
        int l =0, r = cleans.length()-1;
        while(l <=r) {
            if (cleans[l] != cleans[r]) {
                return false;
            } else {
                l++;
                r--;
            }
        }
        return true;
    }
};