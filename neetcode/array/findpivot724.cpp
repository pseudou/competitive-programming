#include<iostream>
#include<vector>

using namespace std;

// https://leetcode.com/problems/find-pivot-index/description/
// ans: first find the total sum. Then substract current num from total sum. check if that is equal to
// current sum if yes then return index;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int tsum = 0, sum = 0;

        for(int i:nums) {
            tsum += i;
        }

        for (int i=0; i< nums.size();i++) {
            if ((float)(tsum - nums[i])/2 == (float) sum) {
                return i;
            }
            sum+= nums[i];
        }

        return -1;
    }
};