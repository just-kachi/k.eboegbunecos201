#include <iostream>
using namespace std;

int main() {
    // Initialize the array
    int array[] = {1, 4, 5, 6, 10, 23, 34, 56, 67};
    
    // Calculate the size of the array
    int size = sizeof(array) / sizeof(array[0]);

    // Initialize variables for max and min values
    int maxVal = array[0];
    int minVal = array[0];

    // Loop through the array to find the max and min values
    for (int i = 1; i < size; i++) {
        if (array[i] > maxVal) {
            maxVal = array[i];  // Update max if current value is greater
        }
        if (array[i] < minVal) {
            minVal = array[i];  // Update min if current value is smaller
        }
    }

    // Output the maximum and minimum values
    cout << "Maximum value in the array is: " << maxVal << endl;
    cout << "Minimum value in the array is: " << minVal << endl;

    return 0;
}
