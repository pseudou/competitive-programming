class Solution {
public:
    bool issafe(int n, vector<string>& nQueens, int row, int col) {
        for(int i=0; i<n; i++) {
            if(nQueens[i][col] == 'Q') {
                return false;
            }
        }
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
            if(nQueens[i][j] == 'Q') {
                return false;
            }
        }

        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++) {
            if(nQueens[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
    vector<vector<string>> ans;
    void solve(vector<string> &board, int row, int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int j = 0; j <n; j++) {
            if (issafe(n, board, row, j)) {
                board[row][j] = 'Q';
                solve(board, row + 1, n);
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board (n, string(n, '.'));
        ans.clear();
        solve(board, 0 , n);
        return ans;
    }
};