#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Solves the all-pairs shortest path
// problem using Floyd Warshall algorithm
void floydWarshall(vector<vector<int>> &dist) {

    for (int k =0; k <dist.size(); k++) {
        for (int i =0; i< dist.size(); i++) {
            for (int j =0 ; j < dist.size(); j++) {
                if (i == k || j == k) continue;
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int INF = INT_MAX;
    vector<vector<int>> dist = {
        {0, 4, INF, 5, INF},
        {INF, 0, 1, INF, 6},
        {2, INF, 0, 3, INF},
        {INF, INF, 1, 0, 2},
        {1, INF, INF, 4, 0}
    };

    floydWarshall(dist);
    for(int i = 0; i<dist.size(); i++) {
        for(int j = 0; j<dist.size(); j++) {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}