#include <iostream>
using namespace std;
int score=-45;

int main( ) {
    if(score>=70 && score <=100) {
        cout << "Grade A" <<endl;
        cout << "Excellent" <<endl;
    }
    
    else if(score>=60 && score <=69){
        cout << "Grade B" <<endl;
        cout << "Very Good" <<endl;
    }
    
    else if(score>=50 && score <=59){
        cout << "Grade C" <<endl;
        cout << "Good" <<endl;
    }
    
    else if(score>=40 && score <=49){
        cout << "Grade D" <<endl;
        cout << "Fair" <<endl;
    }
    
    else if(score>=0 && score <= 39){
        cout << "Grade F" <<endl;
        cout << "Poor" <<endl;
    }
    
    else{
        cout  << "Invalid Grade" <<endl;
        cout << "You too stupid ajeh" <<endl;
    }
    
    return 0;
}