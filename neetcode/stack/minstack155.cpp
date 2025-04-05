
// https://leetcode.com/problems/min-stack/
// maintain stack<pair<int,int>> .first is the actual number. .second is the stack minimum which is calculated
// everytime you push.

#include<stack>

using namespace std;

class MinStack {
public:
    stack<pair<int,int>> s;

    MinStack() {
        
    }
    
    void push(int val) {
        if (s.empty()) {
            s.push({val, val});
        } else {
            s.push({val, min(val, s.top().second)});
        }
        
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */