//https://leetcode.com/problems/daily-temperatures/description/

// Ans; have a stack. traverse from right to left. in the stack put only the indexes. Using the stack
// find the next greater element. after finding, use the index.

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=0;
            else ans[i]=st.top()-i;
            st.push(i);
        }
        return ans;
    }
};