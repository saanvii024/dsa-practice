class Solution {
public:

    bool isValid(vector<vector<char>>& board, char dig, int row, int col){

        // check column
        for(int i = 0; i < 9; i++){

            if(board[i][col] == dig)
                return false;
        }

        // check row
        for(int j = 0; j < 9; j++){

            if(board[row][j] == dig)
                return false;
        }

        // check box
        int startrow = (row/3) * 3;
        int startcol = (col/3) * 3;

        for(int i = startrow; i < startrow + 3; i++){

            for(int j = startcol; j < startcol + 3; j++){

                if(board[i][j] == dig)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board){

        for(int row = 0; row < 9; row++){

            for(int col = 0; col < 9; col++){

                // empty cell
                if(board[row][col] == '.'){

                    // try 1 to 9
                    for(char dig = '1'; dig <= '9'; dig++){

                        if(isValid(board, dig, row, col)){

                            board[row][col] = dig;

                            // recurse
                            if(solve(board))
                                return true;

                            // BACKTRACK
                            board[row][col] = '.';
                        }
                    }

                    // no digit worked
                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {

        solve(board);
    }
};