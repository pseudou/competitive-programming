
// https://leetcode.com/problems/task-scheduler/
// Create a (maxh) priority queue with frequency of tasks. While loop until the end of a cycle (n+1)
// pop max freq element, decrement count, decrement frequency, if still remaining, add to remaining list.
// after pq becomes empty re add the remaining back to pq. Count the decrement and remaining cycle as the
// time taken.

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        

        vector<int>m(26,0);
        for (char c:tasks) {
            m[c-'A']++;
        }

        priority_queue<int> pq;
        for (int i:m) {
            if (i == 0) continue;
            pq.push(i);
        }
        cout << pq.size() <<endl;
        int time =0;
        while(!pq.empty()) {
            vector<int> remaining;
            int cycle = n+1;
            //cout <<"debug1:"<< time << endl;
            while(cycle > 0 && !pq.empty()) {
                //cout <<"debug2:"<< time << endl;
                int mf = pq.top();
                pq.pop();
                cycle--;
                time++;
                mf--;
                if (mf > 0) {
                    remaining.push_back(mf);
                }
            }
            
            for (int i:remaining) {
                pq.push(i);
            }
            if(pq.empty()) break;
            time += cycle;
        }

        return time;
    }
};