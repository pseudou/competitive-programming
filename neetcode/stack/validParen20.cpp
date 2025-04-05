
// https://leetcode.com/problems/valid-parentheses/description/
// create a stack. simple solution.

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        char top;
        for (int i=0; i< s.size();i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            } else {
                if (stk.empty()) return false;
                top = stk.top();
                stk.pop();
                if (s[i] == '}' && top != '{') return false;
                if (s[i] == ')' && top != '(') return false;
                if (s[i] == ']' && top != '[') return false;
            }
        }
        return stk.empty();
    }
};