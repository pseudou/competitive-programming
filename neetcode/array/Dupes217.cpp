#include<iostream>
#include<unordered_set>

// https://leetcode.com/problems/contains-duplicate/description/
// ans: create a hash set if check if the element exists

using namespace std;
class Dupes217 {
public:
    bool containsDupes(vector<int> &a) {
        unordered_set<int> s;

        for (int i:a) {
            if (s.find(i) == s.end()) {
                s.insert(i);
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Dupes217 s = Dupes217();
    vector<int> test = {1,2,3, 1};
    cout << s.containsDupes(test);
    return 0;
}
