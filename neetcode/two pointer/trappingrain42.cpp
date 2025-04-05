#include<vector>

using namespace std;

// H https://leetcode.com/problems/trapping-rain-water/description/
// Ans; have lm, rm, i, j. i and j are the two pointers. if lm <= rm , find area of width 1 using lm because
// it is minimum, then increment i to find because you are trying to find the max lm here. vice versa for rm and j.


class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size(), lm=a[0], rm=a[a.size()-1], i=0, j= a.size()-1, area = 0;

        while(i < j) {
            if (lm <= rm) {
                area += (lm - a[i]);
                i++;
                lm = max(lm, a[i]);
            } else {
                area += rm - a[j];
                j--;
                rm = max(rm, a[j]);
            }
        }

        return area;


        // int n= a.size();
        // vector<pair<int,int>> lrm(n);
        // int clm=0, crm=0;
        // for (int i=0; i<n;i++) {

        //     lrm[i].first  = clm;
        //     clm = max(clm, a[i]);

        //     lrm[n-i-1].second = crm;
        //     crm = max(crm, a[n-i-1]);
        // }

        // int area = 0;
        // for (int i=0; i<n;i++) {
        //     if (min(lrm[i].first, lrm[i].second) - a[i] > 0) 
        //     area += min(lrm[i].first, lrm[i].second) - a[i]; 
        // }

        // return area;

    }
};