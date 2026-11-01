
class Solution {
public:

    bool isSafe(vector<string>& board, int row, int n, int col) {

        // Check vertically upward
        for (int i = row; i >= 0; i--) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void nqueen(int n, vector<string>& board,
                vector<vector<string>>& ans, int row) {

        // Base case
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {

            if (isSafe(board, row, n, j)) {

                board[row][j] = 'Q';

                nqueen(n, board, ans, row + 1);

                // Backtracking
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        nqueen(n, board, ans, 0);

        return ans;
    }
};
