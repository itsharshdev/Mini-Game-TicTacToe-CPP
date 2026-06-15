#include <iostream>
using namespace std;

char board[3][3];

void initializeBoard() {
    char ch = '1';

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ch++;
        }
    }
}

void displayBoard() {

    cout << "\n";

    for(int i = 0; i < 3; i++) {

        cout << " ";

        for(int j = 0; j < 3; j++) {

            cout << board[i][j];

            if(j < 2)
                cout << " | ";
        }

        cout << endl;

        if(i < 2)
            cout << "---|---|---" << endl;
    }

    cout << endl;
}

bool checkWin(char player) {

    for(int i = 0; i < 3; i++) {

        if(board[i][0] == player &&
           board[i][1] == player &&
           board[i][2] == player)
            return true;

        if(board[0][i] == player &&
           board[1][i] == player &&
           board[2][i] == player)
            return true;
    }

    if(board[0][0] == player &&
       board[1][1] == player &&
       board[2][2] == player)
        return true;

    if(board[0][2] == player &&
       board[1][1] == player &&
       board[2][0] == player)
        return true;

    return false;
}

bool boardFull() {

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {

            if(board[i][j] != 'X' &&
               board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

void makeMove(int choice, char player) {

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if(board[row][col] == 'X' ||
       board[row][col] == 'O') {

        cout << "\nCell already occupied!\n";
        return;
    }

    board[row][col] = player;
}

int main() {

    char playAgain;

    do {

        initializeBoard();

        char currentPlayer = 'X';

        while(true) {

            displayBoard();

            int choice;

            cout << "Player "
                 << currentPlayer
                 << ", enter position (1-9): ";

            cin >> choice;

            if(choice < 1 || choice > 9) {
                cout << "\nInvalid Move!\n";
                continue;
            }

            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            if(board[row][col] == 'X' ||
               board[row][col] == 'O') {

                cout << "\nCell already occupied!\n";
                continue;
            }

            makeMove(choice, currentPlayer);

            if(checkWin(currentPlayer)) {

                displayBoard();

                cout << "\nPlayer "
                     << currentPlayer
                     << " Wins!\n";

                break;
            }

            if(boardFull()) {

                displayBoard();

                cout << "\nIt's a Draw!\n";

                break;
            }

            if(currentPlayer == 'X')
                currentPlayer = 'O';
            else
                currentPlayer = 'X';
        }

        cout << "\nPlay Again? (Y/N): ";
        cin >> playAgain;

    } while(playAgain == 'Y' || playAgain == 'y');

    cout << "\nThanks for Playing!\n";

    return 0;
}
