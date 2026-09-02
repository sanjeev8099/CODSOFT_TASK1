#include <iostream>
#include <random>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 100);

    char playAgain;
    do {
        int secret = dist(gen);
        int guess, attempts = 0;

        cout << "\n=== NUMBER GUESSING GAME ===\n";
        cout << "Guess a number between 1 and 100.\n";

        do {
            cout << "Enter your guess: ";
            cin >> guess;
            attempts++;

            if (guess < secret)
                cout << "Too low! Try again.\n";
            else if (guess > secret)
                cout << "Too high! Try again.\n";
            else
                cout << "Correct! You guessed it in " << attempts << " attempts.\n";
        } while (guess != secret);

        cout << "Play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}