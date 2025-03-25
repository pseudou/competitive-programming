#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
    vector<vector<string>> groupana(vector<string> &l) {
        unordered_map<string, vector<string>> m;
        string temp;
        for (string &s:l) {
            temp =s;
            sort(temp.begin(), temp.end());
            m[temp].push_back(s);
        }

        vector<vector<string>> ans;

        for (auto &[_,v]: m) {
            ans.push_back(v);
        }

        return ans;
    }

};

int main() {
    return 0;
}