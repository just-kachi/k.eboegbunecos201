#include <iostream>
using namespace std;

int main ()
{
    int matrix1 [] = {1,2,3};
    int matrix2 [] = {4,5,6};
    int matrix3 [] = {7,8,9};

    int addition [3];
    for (int i = 0; i < 3; i++ ) 
    {
        addition[i] = matrix1[i] + matrix2[i] + matrix3[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cout << addition[i] << " ";
    }
    return 0;

}