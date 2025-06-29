#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// Define Interval class
class Interval {
public:
    int start, end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// Sort comparator function
bool sortComp(const Interval &a, const Interval &b) {
    return (a.start != b.start) ? a.start < b.start : a.end < b.end;
}

class Solution {
public:
    int minMeetingRooms(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), sortComp);
        set<int> s;
        for (Interval i : intervals) {

            auto it = s.lower_bound(-i.start);
            if (it == s.end()) {
                s.insert(-i.end);
            } else {
                s.erase(it);
                s.insert(-i.end);
                cout << "debug";
                cout << -(*it) << " " << -i.end << endl;
            }

        }
        return s.size();
    }
};

// Helper to run a test case
void runTest(vector<pair<int, int>> input, int expected) {
    vector<Interval> intervals;
    for (auto p : input) intervals.push_back(Interval(p.first, p.second));

    Solution sol;
    int result = sol.minMeetingRooms(intervals);

    cout << "Input: ";
    for (auto p : input) cout << "(" << p.first << "," << p.second << ") ";
    cout << "\nExpected: " << expected << ", Got: " << result << endl;

    if (result == expected) {
        cout << "✅ Passed\n\n";
    } else {
        cout << "❌ Failed\n\n";
    }
}

// Main function to run tests
int main() {
    runTest({{0, 30}, {5, 10}, {15, 20}}, 2);
    runTest({{7, 10}, {2, 4}}, 1);
    runTest({{0, 8}, {8, 10}}, 1); // No overlap
    runTest({{1, 5}, {2, 6}, {4, 8}}, 3);
    runTest({}, 0); // No meetings

    return 0;
}