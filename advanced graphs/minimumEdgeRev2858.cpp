#include<map>

using namespace std;

// H https://leetcode.com/problems/minimum-edge-reversals-so-every-node-is-reachable/
// Ans: Remember there is no cyclic! Do a dfs with return as reversals needs to reach the end. Since
// there is no cycle, no need to keep a track of visited nodes. Doing that, initially find the reversal
// needed for any random node. Now comes the DP. starting with the same random node, traverse the graph
// in the same dfs way but this time if a directed edge then add one to the number of reversal needed
// from the random node to reach the current node. If reverse directed edge, then substract one from the
// random node to reach the current node.

class Solution {
    vector<unordered_map<int,bool>> adj;
    vector<int> ans;

public:

    int dfs(int start, int prev) {
        int sum = 0;
        for (auto [node, directed]: adj[start]) {
            if (node == prev) continue;
            int rev = directed ? 0 : 1;
            sum += rev + dfs(node, start);
        }

        return sum;

    }

    void branch(int start, int prev) {
        for (auto [node, directed]: adj[start]) {
            if (node == prev) continue;
            int delta = directed ? 1:-1;
            ans[node] = ans[start] + delta;
            branch(node, start);
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        adj.clear();
        adj.resize(n);
        ans.clear();
        ans.resize(n,0);

        for (int i =0; i<edges.size(); i++) {
            adj[edges[i][0]][edges[i][1]] = true;
            adj[edges[i][1]][edges[i][0]] =  false;
        }

        ans[0] = dfs(0, -1);
        branch(0, -1);

        return ans;

    }
};