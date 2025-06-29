#include<vector>
#include<queue>
#include<iostream>

using namespace std;

vector<vector<pair<int,int>>> constructAdj(vector<vector<int>> &edges, int v) {
    vector<vector<pair<int,int>>> adj(v);

    for (auto &edge:edges) {
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }

    return adj;

}

// Returns shortest distances from src to all other vertices
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src){

    vector<vector<pair<int,int>>> adj = constructAdj(edges, V);

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minh;

    minh.push({0, src});

    while(!minh.empty()) {
        auto [dis, u] = minh.top();
        minh.pop();

        for (auto &[v, weight]: adj[u]) {
            if (dis + weight < dist[v]) {
                dist[v] = dis + weight;
                minh.push({dist[v], v});
            }
        }
    }

    return dist;
}

// Driver program to test methods of graph class
int main(){
    int V = 5;
    int src = 0;

    // edge list format: {u, v, weight}
    vector<vector<int>> edges = {{0, 1, 4}, {0, 2, 8}, {1, 4, 6},
                                 {2, 3, 2}, {3, 4, 10}};

    vector<int> result = dijkstra(V, edges, src);

    // Print shortest distances in one line
    for (int dist : result)
        cout << dist << " ";

    return 0;
}