#include<iostream>
#include<vector>

using namespace std;

// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// use two pointer. if l+r > t then r-- if l+r > t l++;
class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        int l =0, r= a.size()-1;

        while(l<r) {
            if (a[l]+a[r] == t) {
                a.resize(2);
                a[0] = l+1;
                a[1] = r+1;
                return a;
            } else if (a[l]+a[r] > t){
                r--;
            } else {
                l++;
            }
        }
        return a;

    }
};