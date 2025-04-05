#include<vector>
#include<iostream>
using namespace std;

// https://neetcode.io/problems/string-encode-and-decode
// encode with #stringlength#string

class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (string str:strs) {
            encoded += '#' + to_string(str.size()) +'#';
            encoded += str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string> decoded;
        while(i< s.size()) {
            //cout << i << " " <<endl;
            if (s[i] == '#') {
                i++;
                string cs = "";
                while(s[i] != '#') {
                    cs+= s[i];
                    i++;
                }
                i++;
                int ssize = stoi(cs);
                cs = "";
                while(ssize !=0) {
                    cs+= s[i];
                    i++;
                    ssize--;
                }
                decoded.push_back(cs);
            }
        }

        return decoded;


    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> test = {"asfjbcnaf", "123412u hjsdan", "sadhbasdjh21"};
    Solution s = Solution();
    string encoded = s.encode(test);
    test = s.decode(encoded);
    for (int i=0; i<test.size();i++) {
        cout << test[i] << '\n';
    }

    return 0;
}
