#include <iostream>
using namespace std;

int main() {
    int n; // number of numbers to compare
    cout << "Enter the number of values you want to compare: ";
    cin >> n;

    // Check if the input is valid
    if (n <= 0) {
        cout << "Please enter a positive integer greater than 0." << endl;
        return 1;
    }

    int number; // variable to store each input number
    int largest; // variable to store the largest number

    // Ask for the first number and set it as the initial largest number
    cout << "Enter number 1: ";
    cin >> largest; // initialize the largest number

    // Compare the rest of the numbers
    for (int i = 2; i <= n; i++) {
        cout << "Enter number " << i << ": ";
        cin >> number;

        // Update largest if the current number is greater
        if (number > largest) {
            largest = number;
        }
    }

    // Output the largest number
    cout << "The largest number among the entered values is: " << largest << endl;

    return 0;
}
