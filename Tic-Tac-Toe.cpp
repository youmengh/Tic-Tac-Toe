#include <iostream>

using namespace std;

char position;   // position a player entered
bool turn;       // 0 = player 1's turn, 1 = player 2's turn
char play_again; // variable to track if player wants to play a new game

int winner;        // 1 = player 1 wins, 2 = player 2 wins
bool draw = false; // true if game is a draw, false otherwise
bool game_over;    // false = game not over, true = game over

// board is an array representaion of the Tic-Tac-Toe grid of char values from 1 to 9
char board[9];

// default grid of the game used for resetting
char default_board[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

// function for printing the Tic-Tac-Toe grid neatly
void printBoard()
{
    for (int i = 0; i < 9; i += 3)
    {
        cout << "|  " << board[i] << "  ";
        cout << "|  " << board[i + 1] << "  ";
        cout << "|  " << board[i + 2] << "  |\n";
    }
}

// function to check for a winner
void checkWinner()
{

    // checking the columns for winner
    for (int i = 0; i < 3; i++)
    {
        if (board[i] == 'X' && board[i + 3] == 'X' && board[i + 6] == 'X')
        {
            winner = 1;
        }
        else if (board[i] == 'O' && board[i + 3] == 'O' && board[i + 6] == 'O')
        {
            winner = 2;
        }
    }

    // checking the rows for winner
    for (int i = 0; i < 9; i += 3)
    {
        if (board[i] == 'X' && board[i + 1] == 'X' && board[i + 2] == 'X')
        {
            winner = 1;
        }
        else if (board[i] == 'O' && board[i + 1] == 'O' && board[i + 2] == 'O')
        {
            winner = 2;
        }
    }

    // checking the diagonals for winner
    if ((board[0] == 'X' && board[4] == 'X' && board[8] == 'X') || (board[2] == 'X' && board[4] == 'X' && board[6] == 'X'))
    {
        winner = 1;
    }
    else if ((board[0] == 'O' && board[4] == 'O' && board[8] == 'O') || (board[2] == 'O' && board[4] == 'O' && board[6] == 'O'))
    {
        winner = 2;
    }
}

// function for checking when there's no winner
void checkDraw()
{
    int count = 0; // count the number of cells on board that are not a char number 1-9

    for (int i = 0; i < 9; i++)
    {
        if (board[i] != '1' && board[i] != '2' && board[i] != '3' && board[i] != '4' && board[i] != '5' && board[i] != '6' && board[i] != '7' && board[i] != '8' && board[i] != '9')
        {
            count++;
        }
    }

    if (count == 9)
    {
        draw = true;
    }
    else
    {
        draw = false;
    }
}

// function for resetting the game (resets all variables to their initial states)
void reset()
{
    position = 0;
    turn = false;
    play_again = 'y';

    winner = 0;
    game_over = false;

    for (int i = 0; i < 9; i++)
    {
        board[i] = default_board[i];
    }
}

int main()
{

    reset(); // initializes the game

    while (play_again == 'y')
    {

        reset();
        cout << "\nNEW GAME:\n";

        while (game_over == false)
        {
            cout << "\n";
            printBoard();
            if (turn == false)
            {
                cout << "Player 1's Turn\n";
                cin >> position;

                for (int i = 0; i < 9; i++)
                {
                    if (board[i] == position)
                    {
                        board[i] = 'X';
                        turn = true;
                    }
                }
            }
            else
            {
                cout << "Player 2's Turn\n";
                cin >> position;

                for (int i = 0; i < 9; i++)
                {
                    if (board[i] == position)
                    {
                        board[i] = 'O';
                        turn = false;
                    }
                }
            }

            // checks for a winner after entry
            checkWinner();

            // sets game_over to true if winner exists
            if (winner == 1)
            {
                game_over = true;
                cout << "\n";
                printBoard();
                cout << "\nPlayer 1 wins!\n";
            }
            else if (winner == 2)
            {
                game_over = true;
                cout << "\n";
                printBoard();
                cout << "\nPlayer 2 wins!\n";
            }
            else
            {
                game_over = false;
            }

            // checks for the case of a draw
            checkDraw();
            if (draw == true && winner == 0)
            {
                game_over = true;
                cout << "\n";
                printBoard();
                cout << "\nDraw.\n";
            }
        }
        cout << "\nEnter 'y' to play a new game, 'n' to stop.\n";
        cin >> play_again;
    }
    cout << "\nGAME OVER. Thanks for playing.\n";
}
