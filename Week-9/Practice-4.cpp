#include <iostream>
using namespace std;

class csc201 { //the class
public:  //access specifier
    int score; //attribute score
    string name; //attribute grade
    char grade; //sttribute grade
    // Declaration
public:
csc201(){ //the constructor
        cout<<"student must pass csc1001\n";
    cout<<"To pass the course, the student must have a minimum score of 48\n";
}
};

int main(){
    csc201 student1;
    student1.score=20;
    student1.grade='F';
    student1.name="Bello Moses Eromsele";
    cout << "Student1's Name = "<<student1.name<<", grade ="<<student1.grade<<", and score =" <<student1.score<<endl;
}



