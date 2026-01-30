#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int systemNumber = rand() % 50 + 1;
    int userGuess;
    int attempts = 0;

    cout << "Welcome to the Number guessing challenge!\n";
    cout << "I have selected a number between 1 and 50.\n";

    while (true) {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        if (userGuess > systemNumber) {
            cout << "Your guess is higher than the number.\n";
        } 
        else if (userGuess < systemNumber) {
            cout << "Your guess is lower than the number.\n";
        } 
        else {
            cout << "Correct! You found the number in "
                 << attempts << " attempts.\n";
            break;
        }
    }

    cout << "Game over.Thanks for playing!\n";
    return 0;
}
