class Solution {
public:
    bool isValid(int row, int col, char c, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            // Check row
            if (board[row][i] == c) return false;

            // Check column
            if (board[i][col] == c) return false;

            // Check 3x3 grid
            int r = 3 * (row / 3) + i / 3;
            int cc = 3 * (col / 3) + i % 3;
            if (board[r][cc] == c) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                if (board[row][col] == '.') {
                    for (char c = '1'; c <= '9'; c++) {

                        if (isValid(row, col, c, board)) {
                            board[row][col] = c;

                            if (solve(board)) return true;

                            board[row][col] = '.'; // backtrack
                        }
                    }
                    return false; // no number fits
                }
            }
        }
        return true; // solved
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
