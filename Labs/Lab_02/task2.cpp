#include <iostream>
#include <string>
using namespace std;

class TicTacToe
{
private:
    int board[3][3];

public:
    TicTacToe()
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = 0;
    }

    void clearboard()
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = 0;
    }

    void tostring() const
    {
        cout << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << board[i][j];
                if (j < 2)
                    cout << " | ";
            }
            if (i < 2)
                cout << "\n----------\n";
        }
        cout << endl;
    }

    int gamestatus() const
    {
        // check rows and columns
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] != 0 &&
                board[i][0] == board[i][1] &&
                board[i][1] == board[i][2])
                return board[i][0];

            if (board[0][i] != 0 &&
                board[0][i] == board[1][i] &&
                board[1][i] == board[2][i])
                return board[0][i];
        }

        // diagonals
        if (board[0][0] != 0 &&
            board[0][0] == board[1][1] &&
            board[1][1] == board[2][2])
            return board[0][0];

        if (board[0][2] != 0 &&
            board[0][2] == board[1][1] &&
            board[1][1] == board[2][0])
            return board[0][2];

        // check if game still running
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == 0)
                    return 0;   // game continues

        return -1; // draw
    }

    bool move(int player, int row, int col)
    {
        if (row < 0 || row > 2 || col < 0 || col > 2)
            return false;

        if (board[row][col] != 0)
            return false;

        board[row][col] = player;
        return true;
    }
};

int main()
{
    TicTacToe game;
    int player = 1;
    int row, col;
    int status = 0;

    cout << "Welcome to Tic-Tac-Toe!\n";
    game.tostring();

    while ((status = game.gamestatus()) == 0)
    {
        cout << "\nPlayer " << player << "'s turn (row col): ";
        cin >> row >> col;

        if (!game.move(player, row, col))
        {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        game.tostring();
        player = (player == 1) ? 2 : 1;
    }

    if (status == 1 || status == 2)
        cout << "\nPlayer " << status << " wins!\n";
    else
        cout << "\nThe game is a draw!\n";

    return 0;
}
