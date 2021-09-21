/* Tic-tac-toe is played by two players A and B on a 3 x 3 grid.

Here are the rules of Tic-Tac-Toe:

Players take turns placing characters into empty squares (" ").
The first player A always places "X" characters, while the second player B always places "O" characters.
"X" and "O" characters are always placed into empty squares, never on filled ones.
The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
Given an array moves where each element is another array of size 2 corresponding to the row and column of the grid where they mark their respective character in the order in which A and B play.

Return the winner of the game if it exists (A or B), in case the game ends in a draw return "Draw", if there are still movements to play return "Pending".

You can assume that moves is valid (It follows the rules of Tic-Tac-Toe), the grid is initially empty and A will play first. */

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find Winner on a Tic Tac Toe Game.
// Memory Usage: 8.3 MB, less than 57.00% of C++ online submissions for Find Winner on a Tic Tac Toe Game.

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        for(int i = 0; i < moves.size(); i++) {
            if(i % 2 == 0) {
                board[moves[i][0]][moves[i][1]] = 'X';
            }
            else {
                board[moves[i][0]][moves[i][1]] = 'O';
            }
        }
        if((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') || (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') || (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') || (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') || (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') || (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') || (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')) {
            return "A";
        }
        else if((board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') || (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') || (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') || (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') || (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') || (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') || (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') || (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')) {
            return "B";
        }
        else if(board[0][0] == ' ' || board[0][1] == ' ' || board[0][2] == ' ' || board[1][0] == ' ' || board[1][1] == ' ' || board[1][2] == ' ' || board[2][0] == ' ' || board[2][1] == ' ' || board[2][2] == ' ') {
            return "Pending";
        }
        return "Draw";
    }
    
private:
    vector<vector<char>> board{{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
};
