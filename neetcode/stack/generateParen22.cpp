#include<string>
#include<vector>

using namespace std;

// https://leetcode.com/problems/generate-parentheses/description/
// Ans: use recursion to generate combination. Also remember, when putting close into the generated string
// it means that there must be an open paren in the string already.

class Solution {
public:
    int open, close;
    vector<string> ans;

    void generate(string s) {
        if (open == 0 && close == 0){
            ans.push_back(s);
            return;
        }
        if (open > 0) {
            open--;
            generate( s + '(');
            open++;
        }
        if (close > 0 && close > open) {
            close--;
            generate (s + ')');
            close++;
        }
    }




    vector<string> generateParenthesis(int n) {
        open = n; close = n;
        ans.clear();
        generate("");
        return ans;
    }
};