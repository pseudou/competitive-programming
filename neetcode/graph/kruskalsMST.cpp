#include <iostream>
#include<unordered_set>
#include<algorithm>

using namespace std;
bool comparator(vector<int> &a,vector<int> &b){
    if(a[2]<=b[2])return true;
    return false;
}
int kruskalsMST(int V, vector<vector<int>> &edges) {

    unordered_set<int> s;
    // Sort all edhes
    sort(edges.begin(), edges.end(),comparator);

    int cost = 0, count = 0;
    
    for (auto &e : edges) {
        int x = e[0], y = e[1], w = e[2];
        
        // Make sure that there is no cycle
        if (s.find(x) == s.end() || s.find(y) == s.end()) {
            s.insert(x);
            s.insert(y);
            cost += w;
            if (++count == V - 1) break;
        }
    }
    return cost;
}

int main() {

    // An edge contains, weight, source and destination
    vector<vector<int>> edges = {
        {0, 1, 10}, {1, 3, 15}, {2, 3, 4}, {2, 0, 6}, {0, 3, 5}
    };

    cout<<kruskalsMST(4, edges);

    return 0;
}