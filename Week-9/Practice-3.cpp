#include <iostream>
using namespace std;

class csc201 { //the class

public:          // access specifier
    int score;   //attribute score
    string name; //attribute grade 
    char grade;  //attribute grade
    //Declaration
public:
void prerequisite();
void verdict();
} ;
//Outside class definition
void csc201::verdict(){
    cout<<"To pass the course, the student must have a minimum score of 40"
}
void csc201::prerequisite(){
    cout <<"Student must pass csc101\n";
}

int main(){
    csc201 studnet1;
    student1.score=20;
    student1.grades='F';
    student1.name="Bello Moses Eromsele";
    cout << "Student1's Name = "<<student1.name<<", grade ="<<student1.grade<<", and score =" <<student1.score<<endl;
student1.prerequisite();
student1.verdict();
}