#include <iostream>
using namespace std;

int main() {
    char ch;  // Variable to store the character input by the user

    // Ask the user to enter a character
    cout << "Enter a character: ";
    cin >> ch;

    // Check if the character is a vowel
    if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U') {
        cout << ch << " is a vowel." << endl;
    }
    // Check if the character is a consonant
    else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        cout << ch << " is a consonant." << endl;
    }
    // Handle invalid input
    else {
        cout << "Please enter a valid alphabetic character." << endl;
    }

    return 0;
}
