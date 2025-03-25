#include<vector>
#include<iostream>

using namespace std;
class Solution {
public:
    static vector<int> replace(vector<int>& v) {
        int mx =v[v.size()-1], temp;
        v[v.size()-1] =-1;
        for (int i=v.size()-2; i>=0;i-- ) {
            temp = v[i];
            v[i] = mx;
            mx = max(mx, temp);
        }

        return v;
    }
};

int main() {
    vector <int> test = {17,18,5,4,6,1};
    Solution s = Solution();
    s.replace(test);
    for (int i=0; i<test.size() ;i++) {
        cout << test[i] << " ";
    }
    return 0;
}