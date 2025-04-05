#include <vector>
#include <iostream>

using namespace std;

// E https://leetcode.com/problems/can-place-flowers/description/
// Ans: simple one if condition but many cases in the condition!

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        for (int i=0; i< flowerbed.size(); i++) {
            if (flowerbed[i] == 0 && (i==0 || flowerbed[i-1] == 0) && (i==flowerbed.size()-1 || flowerbed[i+1] == 0)) {
                n--;
                flowerbed[i] =1;
                i++;
            }
            if (n <= 0) return true;
        }
        return false;

        // int start = -2;
        // for (int i=0;i<flowerbed.size(); i++) {
        //     if (flowerbed[i] == 1) {
        //         int val = floor((i-start-2)/2);
        //         n -= max(0, val);
        //         start = i;
        //     }
        //     if (i == flowerbed.size()-1 && flowerbed[flowerbed.size()-1] != 1) {
        //         int val = floor((flowerbed.size() + 1-start-2)/2);
        //         n -= max(0, val);
        //     }
        // }
        // return n <= 0;

    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}