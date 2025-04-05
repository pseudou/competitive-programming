#include<stack>

using namespace std;

// https://leetcode.com/problems/implement-queue-using-stacks/description/

// push will be O(n), others will be O(1). maintain a reverse stack.
class MyQueue {
public:
    stack <int> reverse;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack <int> temp;
        while (!reverse.empty()){
            temp.push(reverse.top());
            reverse.pop();
        }
        reverse.push(x);
        while(!temp.empty()) {
            reverse.push(temp.top());
            temp.pop();
        }
    }
    
    int pop() {
        int temp = reverse.top();
        reverse.pop();
        return temp;
    }
    
    int peek() {
        return reverse.top();
    }
    
    bool empty() {
        return reverse.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */