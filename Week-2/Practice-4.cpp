#include <iostream>
using namespace std;
int main() {
    int a = 25;
    int b = 20;
    do {

        b++;
        cout << b<<endl;
    } while ( b > a) ; // The output will be 21
    return 0; //"Do" loop runs the whole code first, before checking for the conditions
}