class Solution {
public:

    bool topSort(vector<vector<int>> &adj, vector<pair<bool,bool>> &visited, int p, int x) {
        if (visited[x].second) return true;
        if (visited[x].first) return false;
        visited[x] = {true, true};
        for (int i=0; i < adj[x].size(); i++) {
            if (p == adj[x][i]) continue;
            auto p = topSort(adj, visited, x, adj[x][i]);
            if (p) return p;
        }
        visited[x] = {true, false};
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() < n -1) return false;
        vector<vector<int>> adj(n);
        vector<pair<bool,bool>> visited(n);

        for (int i=0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for (int i =0 ; i< n; i++) {
            bool p = topSort(adj, visited, -1, i);
            if (p) return false;
        }
        return true;
    }
};
