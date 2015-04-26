class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool isNumValid[10];

        // Check the row.
        for (vector<vector<char> >::iterator it = board.begin(); it != board.end(); ++it) {
            memset(isNumValid, false, 10);
            for (vector<char>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
                if ('.' == *it2)
                    continue;
                if (true == isNumValid[int(*it2)-48]) {
                    return false;
                }
                isNumValid[int(*it2)-48] = true;
            }
        }

        int max_row = board.size();
        int max_col = board[0].size();

        // Check the col.
        for (int col = 0; col < max_col; ++col) {
            memset(isNumValid, false, 10);
            for (int row = 0; row < max_row; ++row) {
                if ('.' == board[row][col])
                    continue;
                int num = int(board[row][col]) - 48;
                if (true == isNumValid[num]) {
                    return false;
                }
                isNumValid[num] = true;
            }
        }

        // Check the square.
        for (int row = 0; row < max_row; row += 3)
            for (int col = 0; col < max_col; col += 3) {
                memset(isNumValid, false, 10);
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        if ('.' == board[row+i][col+j])
                            continue;
                        int num = int(board[row+i][col+j]) - 48;
                        if (true == isNumValid[num]) {
                            return false;
                        }
                        isNumValid[num] = true;
                    }
                }
            }

        return true;
    }
};