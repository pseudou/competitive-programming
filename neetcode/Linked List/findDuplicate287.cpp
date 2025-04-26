
// https://leetcode.com/problems/find-the-duplicate-number/description/
// linked List, find the cycle. lets consider a->b->c->a. slow pointer and the fast pointer meets again
// at c. so distance travelled by slow is X + Y. distance travelled by fast pointer is
// X + Y + Z + Y. // since speedslow *2 = speedfast => 2(x+y) = x + z + 2y => x = z
// hence have a another while loop to find the meeting point. The position pointing to this meeting point is
// is the duplicate number.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int s = 0, f = 0;

        while (true) {
            //cout << nums[s] << " " << nums[f] <<endl;
            s = nums[s];
            f = nums[nums[f]];
            if (s== f) break;
        }
        s = 0;
        while (f != s) {
            f = nums[f];
            s = nums[s];
        }
        return s;
    }
};