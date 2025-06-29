#include<vector>
#include<unordered_set>
#include<iostream>
using namespace std;
class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: return an integer, denote the number of distinct islands
     */
    vector<vector<bool>> visited;

    void dfs(vector<vector<int>> &grid, int x, int y, string &s) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || visited[x][y] || grid[x][y] != 1) {
            s += 'B';
            return;
        }
        visited[x][y] = true;
        s += 'U';
        dfs(grid, x - 1, y, s);
        s += 'D';
        dfs(grid, x + 1, y, s);
        s += 'L';
        dfs(grid, x, y - 1, s);
        s += 'R';
        dfs(grid, x, y + 1, s);
        s += 'B';
    }
    int numberofDistinctIslands(vector<vector<int>> &grid) {
        string s = "";
        visited = vector<vector<bool>> ( grid.size(), vector<bool>(grid[0].size(), false));
        unordered_set<string> unique;
        for (int i=0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    s = "";
                    dfs(grid,i, j, s);
                    unique.insert(s);
                }
            }
        }
        return unique.size();
    }
};

int main() {
    vector<vector<int>> grid = {{1,1,0,0,1}, {1,0,0,0,0}, {1,1,0,0,1}, {0,1,0,1,1}};
    cout << Solution().numberofDistinctIslands(grid);
    return 0;
}