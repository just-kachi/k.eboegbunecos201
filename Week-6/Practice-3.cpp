#include <iostream>
using namespace std;

int *add(int a, int b)
{
    static int sum = a + b;
    return &sum;
}

int main()
{
    int *p = NULL, num1 = 1, num2 = 6;
    p = add(num1, num2);
    cout << "*p = " << *p << endl;
    cout << "p = " << p << endl;
    return 0;
}