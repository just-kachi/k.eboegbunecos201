#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to scramble a word by shuffling its letters
string scrambleWord(const string& word) {
    string scrambled = word;
    for (int i = 0; i < scrambled.size(); i++) {
        int j = rand() % scrambled.size();
        swap(scrambled[i], scrambled[j]);
    }
    return scrambled;
}

// Function to display the current word with correct letters revealed
void displayCurrentWord(const string& word, const vector<bool>& guessed) {
    for (int i = 0; i < word.size(); i++) {
        if (guessed[i]) {
            cout << word[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

int main() {
    srand(time(0)); // Seed for randomization

    // List of words
    vector<string> words = {"apple", "banana", "cherry", "date", "grape"};
    int currentWordIndex = 0;
    int attemptsLeft = 5;
    int getLetterCount = 5;
    
    // Game loop
    while (currentWordIndex < words.size()) {
        string word = words[currentWordIndex];
        string scrambled = scrambleWord(word);
        vector<bool> guessed(word.size(), false); // Track guessed letters

        cout << "Scrambled word: " << scrambled << endl;
        displayCurrentWord(word, guessed);
        cout << "You have " << attemptsLeft << " 'Get Letter' attempts left." << endl;

        char action;
        while (attemptsLeft > 0) {
            cout << "Enter 'p' to get a letter, 'h' for a hint, 'n' for next word, or guess the word: ";
            cin >> action;

            if (action == 'p') { // Get a letter
                if (getLetterCount > 0) {
                    // Reveal the next correct letter
                    for (int i = 0; i < word.size(); i++) {
                        if (!guessed[i]) {
                            guessed[i] = true;
                            getLetterCount--;
                            attemptsLeft--;
                            break;
                        }
                    }
                    displayCurrentWord(word, guessed);
                    cout << "You have " << attemptsLeft << " 'Get Letter' attempts left." << endl;
                } else {
                    cout << "No more 'Get Letter' attempts available!" << endl;
                }
            } 
            else if (action == 'h') { // Give a hint
                cout << "Hint: The word starts with '" << word[0] << "'." << endl;
            }
            else if (action == 'n') { // Move to the next word
                if (currentWordIndex < words.size() - 1) {
                    currentWordIndex++;
                    attemptsLeft = 5; // Reset attempts for the next word
                    getLetterCount = 5; // Reset get letter attempts for the next word
                    break;
                } else {
                    cout << "This is the last word!" << endl;
                    return 0;
                }
            }
            else { // Try to guess the word
                string guess;
                cout << "Enter your guess: ";
                cin >> guess;

                if (guess == word) {
                    cout << "Correct! You guessed the word!" << endl;
                    getLetterCount++;
                    break;
                } else {
                    cout << "Incorrect. Try again!" << endl;
                }
            }

            // Check if all letters have been guessed correctly
            bool wordGuessed = true;
            for (bool guessedLetter : guessed) {
                if (!guessedLetter) {
                    wordGuessed = false;
                    break;
                }
            }

            if (wordGuessed) {
                cout << "You guessed the word correctly!" << endl;
                break;
            }
        }

        // After the current word is finished (either guessed or attempts exhausted), proceed to the next word
        if (currentWordIndex < words.size()) {
            cout << "\nNext word..." << endl;
        }
    }

    return 0;
}
