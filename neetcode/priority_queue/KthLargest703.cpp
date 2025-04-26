
// https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

// One priority queue or min heap. if min heap size is k and if insert val is greater than min heap top
// then insert val and pop. top will always have the kth largest element.

class KthLargest {
public:
    priority_queue<int, vector<int> , greater<int>> pq;
    int k;
    KthLargest(int kk, vector<int>& nums) {
        for (int i=0; i< nums.size(); i++) {
            if (pq.size() < kk) {
                //cout << pq.size() << endl;
                pq.push(nums[i]);
            } else {
                if (nums[i] > pq.top()) {
                    pq.push(nums[i]);
                    pq.pop();
                }
            }
        }
        k = kk;
        //cout << pq.top() ;
    }
    
    int add(int val) {
        if (pq.size() < k) {
            pq.push(val);
            return pq.top();
        } else {
            if (val > pq.top()) {
                pq.push(val);
                pq.pop();
                return pq.top();
            }
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */