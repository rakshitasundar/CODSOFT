#include <iostream>
using namespace std;

char grid[3][3];
char activePlayer;

void resetBoard() {
    char start = '1';
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            grid[i][j] = start++;
}

void showBoard() {
    cout << "\n";
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

bool hasWon() {
    for(int i=0;i<3;i++) {
        if(grid[i][0]==activePlayer &&
           grid[i][1]==activePlayer &&
           grid[i][2]==activePlayer)
            return true;

        if(grid[0][i]==activePlayer &&
           grid[1][i]==activePlayer &&
           grid[2][i]==activePlayer)
            return true;
    }

    if(grid[0][0]==activePlayer &&
       grid[1][1]==activePlayer &&
       grid[2][2]==activePlayer)
        return true;

    if(grid[0][2]==activePlayer &&
       grid[1][1]==activePlayer &&
       grid[2][0]==activePlayer)
        return true;

    return false;
}

bool isDraw() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(grid[i][j] != 'X' && grid[i][j] != 'O')
                return false;
    return true;
}

int main() {
    char choice;
    int position;

    do {
        resetBoard();
        activePlayer = 'X';

        while (true) {
            showBoard();
            cout << "Player " << activePlayer << ", choose a position: ";
            cin >> position;

            int r = (position - 1) / 3;
            int c = (position - 1) % 3;

            if (grid[r][c] != 'X' && grid[r][c] != 'O')
                grid[r][c] = activePlayer;
            else {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            if (hasWon()) {
                showBoard();
                cout << "Player " << activePlayer << " wins the game!\n";
                break;
            }

            if (isDraw()) {
                showBoard();
                cout << "The game ended in a draw.\n";
                break;
            }

            activePlayer = (activePlayer == 'X') ? 'O' : 'X';
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'Y');

    return 0;
}