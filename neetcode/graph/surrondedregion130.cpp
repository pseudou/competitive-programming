class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<bool>> &visited, int x, int y) {
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || visited[x][y] || board[x][y] != 'O') return ;
        visited[x][y] = true;
        dfs(board, visited, x -1, y);
        dfs(board, visited, x + 1, y);
        dfs(board, visited, x , y - 1);
        dfs(board, visited, x , y + 1);
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i <board.size(); i++) {
            dfs(board, visited, i, 0);
            dfs(board, visited, i, board[0].size() - 1);
        }
        for (int i = 0; i <board[0].size(); i++) {
            dfs(board, visited, 0, i);
            dfs(board, visited, board.size() - 1, i);
        }

        for (int i=0; i< board.size(); i++) {
            for (int j=0; j <board[0].size(); j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};