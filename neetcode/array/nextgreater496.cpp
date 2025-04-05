#include <vector>
#include<stack>
#include<iostream>

using namespace std;

// https://leetcode.com/problems/next-greater-element-i/description/
// ans: iterate through the second array from the back, from the stack remove elements if it is lesser
// than current iterator element until you find a greater element. if empty set -1;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int,int> m;
        for (int i=nums2.size() -1 ;i>=0; i--) {
            while(!s.empty() && nums2[i] > s.top() ) {
                s.pop();
            }
            if (s.empty()) {
                m[nums2[i]] = -1;
            } else {
                m[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }

        for (int i=0; i< nums1.size();i++) {
            nums1[i] = m[nums1[i]];
        }
        return nums1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}