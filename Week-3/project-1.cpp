#include <iostream>
using namespace std;

int main() {
    int a; 
    int b; 
    int c; 
    
    for (a = 1; a < 13; a++) {
        for (b = 1; b < 13; b++) {
            c = b * a;
            cout << a << " * " << b << " = " << c << endl;
        }
        cout << endl; 
    }

    return 0;
}