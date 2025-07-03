class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<int> &visited, int x) {
        if (visited[x]) return;
        visited[x] = true;
        for (int i=0; i <adj[x].size(); i++) {
            dfs(adj, visited, adj[x][i]);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> visited(n, false);
        int count =0;
        for (int i=0; i< edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for (int i=0; i<n; i++) {
            if (!visited[i]) {
                count++;
                dfs(adj, visited, i);
            }
        }
        return count;
    }
};
