#include <iostream>
#include <string>
#include <random>
#include <cstdlib>
using namespace std;

string scramble(const string& words) {

    string chars = words;
        for (int i = 0; i < chars.length(); i++) {

            int j = rand() % chars.length();
            char temp = chars[i];
            chars[i] = chars[j];
            chars[j] = temp;
        }

        return chars;
}

int main() {
  
  string ch;
  string words[] = {"apple", "watermelon", "terrible", "beginning", "hatred", "time", "petrol", "excuse", "sport", "rust"};

  for (int i = 0; i < 10; i++) {
    string scrambled =  scramble(words[i]);

 while(0<1){ 
    cout << "Rearrange the word: " <<scrambled<<"  Your Guess: ";
    getline(cin,ch);
  

  if(ch != words[i]) {
    cout << "Your answer is wrong" << endl;
    cout << "Try again" << endl;
    
  } 
  else {
    cout << "Your answer is correct" << endl;
    cout << "Next word" << endl;
    break;
  }
  }
}}
