#include<vector>
#include<stack>
#include<iostream>

using namespace std;


vector<vector<int>> constructadj(int V, vector<vector<int>> &edges)
{

    vector<vector<int>> adj(V);
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
    }

    return adj;
}


void sortedtop(vector<vector<int>> &adj, int curr, int V, stack<int> &s, vector<bool> &visited) {
    visited[curr] = true;
    for (int i = 0; i< adj[curr].size(); i++) {
        if (!visited[adj[curr][i]]) {
            sortedtop(adj, adj[curr][i], V, s, visited);
        }
    }
    s.push(curr);
}

// Function to perform Topological Sort
vector<int> topologicalSort(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj = constructadj(V, edges);

    vector<bool> visited (V, false);
    stack<int> s;
    for (int i=0; i< V; i++) {
        if (!visited[i]) {
            sortedtop(adj, i, V, s, visited);
        }
    }
    vector<int> ans;

    // Append contents of stack
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main()
{

    // Graph represented as an adjacency list
    int v = 6;
    vector<vector<int>> edges = {{2, 3}, {3, 1}, {4, 0}, {4, 1}, {5, 0}, {5, 2}};

    vector<int> ans = topologicalSort(v, edges);

    for (auto node : ans)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}