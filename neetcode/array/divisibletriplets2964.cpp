#include<vector>
#include<iostream>

using namespace std;


// M https://leetcode.com/problems/number-of-divisible-triplet-sums
// Ans: iterate through j 1 to n-1 and k j+1 to n. Now keep a map that contains a[i]%d values count.
// find if  d- (j+k)%d is present in the map. that means that left most element is present. add map count to
// total count because all those i's in map will satisfy the expression.

class Solution {
public:
    int divisibleTriplets(vector<int> & a, int d) {
        vector<int> m (d, 0);

        int count =0;

        m[a[0]%d]++;
        m[d] = m[0];

        for (int j=1; j <a.size() -1; j++) {
            for (int k = j+1; k < a.size(); k++) {
                if (m[d - ((a[j]+a[k])%d)] != 0) {
                    count+= m[d - ((a[j]+a[k])%d)];
                }
            }
            m[a[j]%d]++;
            m[d] = m[0];
        }
        return count;
    }
};

int main() {
    vector<int> test = {3, 3,3, 3};
    Solution s = Solution();
    cout << s.divisibleTriplets(test, 6);
}