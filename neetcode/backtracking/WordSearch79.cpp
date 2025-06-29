class Solution {
public:
    bool exs;
    vector<vector<bool>> used;
    void dfs(vector<vector<char>>& board, int i ,int j, int pos, string word) {
        
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || used[i][j]) {
            return;
        }
        if (board[i][j] != word[pos]) return;
        if (pos == word.size() - 1) {
            exs = true;
            return;
        }
        //cout << i << " " << j << " " << pos << endl;
        used[i][j] = true;
        if (exs == false) dfs(board, i - 1, j, pos +1, word); 
        
        if (exs == false) dfs(board, i + 1, j, pos +1, word); 
        if (exs == false) dfs(board, i , j - 1, pos +1, word); 
        if (exs == false) dfs(board, i , j + 1, pos +1, word); 
        used[i][j] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        exs = false;
        used = vector<vector<bool>> (board.size(), vector<bool>(board[0].size(), false));
        for (int i=0; i< board.size(); i++) {
            for (int j=0; j <board[0].size(); j++) {
                dfs(board, i, j, 0, word);
                if (exs) return exs;
            }
        }
        return exs;
    }
};