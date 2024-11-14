#include <iostream>
using namespace std;

int main() {
    int a; 
    int b; 

    cout << "Enter your upper limit (a): ";
    cin >> a;
    cout << "Enter your lower limit (b): ";
    cin >> b;

    cout << "Odd numbers between " << b << " and " << a << " are:" << endl;
    for (int i = b; i <= a; i++) {
        if (i % 2 != 0) {
            cout << i << endl;
        }
    }

    return 0;
}