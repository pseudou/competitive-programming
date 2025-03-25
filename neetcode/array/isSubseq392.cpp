#include<string>
#include<iostream>

using namespace std;
class Solution {
public:
    bool isSubseq(string s, string t) {
        int ps =0 , pt =0;

        while(ps < s.size() && pt < t.size()) {
            if (s[ps] == t[pt]) {
                ps++;
                pt++;
            } else {
                pt++;
            }
        }

        return ps == s.size();

    }

};

int main() {
    Solution s = Solution();
    cout << s.isSubseq("abc", "ahbgdc");
    return 0;
}