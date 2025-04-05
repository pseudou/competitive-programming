#include<vector>

using namespace std;

// https://leetcode.com/problems/car-fleet/

// Ans: sort the pos. start from the back, calculate the time taken to reach. if time taken to reach is
// greater than prev time taken to reach then this will form a fleet. If time taken is lesser than or equal
// to prevReach then this will join with the existing fleet.

class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& sp) {
        vector<pair<int,int>> v(pos.size());
        for (int i=0; i<pos.size(); i++) {
            v[i] = {pos[i], sp[i]};
        }
        sort(v.begin(), v.end());

        float reach = 0, prevReach = 0;
        int fleet =0;
        for (int i = v.size() - 1; i >=0; i--) {
            //cout << v[i].first << " " << v[i].second << " " << prevReach << endl;
            reach = (float) (target - v[i].first)/v[i].second;
            if (reach > prevReach) {
                fleet++;
                prevReach = reach;
            }
        }
        return fleet;
    }
};