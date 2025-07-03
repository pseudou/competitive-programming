// https://leetcode.com/problems/redundant-connection/

class Solution {
public:
    int findParent(vector<int> &parent, int i) {
        if (parent[i] == i) return i;
        return findParent(parent, parent[i]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        vector<int> parent(n);

        for (int i=0; i< n; i++) {
            parent[i] = i;
        }

        for (int i=0; i< edges.size(); i++) {
            int p1 = findParent(parent, edges[i][0] - 1);
            int p2 = findParent(parent, edges[i][1] - 1);

            if(p1 == p2) {
                return edges[i];
            }
            parent[p2] = p1;
        }

        return {-1, -1};
    }
};