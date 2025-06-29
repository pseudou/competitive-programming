class Solution {
public:

    bool isPalindrome(string s) {
        for (int i =0 ; i< s.size() / 2; i ++) {
            if (s[i] != s[s.size() - i -1]) return false;
        }
        return true;
    }
    vector<vector<string>> ans;
    void part(string s, int i, string subs, vector<string> &curr){
        if (i == s.size() && subs == "") ans.push_back(curr);
        if (i == s.size()) return ;
        if (isPalindrome(subs + s[i])) {
            curr.push_back(subs + s[i]);
            part(s, i + 1, "", curr);
            curr.pop_back();
        }
        part(s, i + 1, subs + s[i], curr);
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        part(s, 0, "", curr);
        return ans;
    }
};