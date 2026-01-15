#include <iostream>
#include <ctime>
using namespace std;

int generateSecretNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void playGame() {
    int secret = generateSecretNumber(1, 100);
    int guess;
    const int maxGuesses = 10;

    cout << "I'm thinking of a number between 1 and 100. Can you guess it?" << endl;

    for (int i = 1; i <= maxGuesses; i++) {
        cout << "Guess " << i << ": ";
        cin >> guess;

        if (guess > secret) {
            cout << "Too high!" << endl;
        } 
        else if (guess < secret) {
            cout << "Too low!" << endl;
        } 
        else {
            cout << "Good job! You got it right! Are you cheating? :c" << endl;
            return;
        }
    }

    cout << "Sorry, you're out of guesses. The correct number was: " << secret << endl;
}

int main(){
    srand(time(0));

    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        playGame();

        cout << "Wanna play again? (Y/N): ";
        cin >> playAgain;
        cout << endl;
    }

    cout << "Goodbye! Hope you had fun :D" << endl;
    return 0;
}