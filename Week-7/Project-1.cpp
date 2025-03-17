#include <iostream>
#include <string>
using namespace std;

int main() {
    string questions[] = {
        "What is the capital of Portugal?",
        "What is the capital of Nigeria?",
        "What is the capital of America?",
        "What is the capital of England?",
        "What is the capital of Ghana?"
    };
    
    string answers[] = {
        "Lisbon", "Abuja", "Washington DC", "London", "Accra"
    };

    string other_options[][4] = {
        {"Lisbon", "Lagos", "Texas", "Zurich"},
        {"New York", "Abuja", "Kyiev", "Johannesburg"},
        {"California", "Texas", "Washington DC", "Miami"},
        {"Manchester", "London", "Zurich", "Kyiev"},
        {"Accra", "Lagos", "Nairobi", "Abuja"}
    };

    int score = 0;
    char user_answer;
    int i = 0;
    
    while (i < 5) {
        cout << "\n" << questions[i] << endl;

        cout << "A or a. " << other_options[i][0] << endl;
        cout << "B or b. " << other_options[i][1] << endl;
        cout << "C or c. " << other_options[i][2] << endl;
        cout << "D or d. " << other_options[i][3] << endl;
        

        cout << "Your answer(A|B|C|D): " << endl; 
        cin >> user_answer;
        user_answer = toupper(user_answer); 
        
        if (user_answer == 'A' && other_options[i][0] == answers[i] || 
            user_answer == 'B' && other_options[i][1] == answers[i] ||
            user_answer == 'C' && other_options[i][2] == answers[i] ||
            user_answer == 'D' && other_options[i][3] == answers[i]) {
            cout << "Correct!" << endl;
            score++;
        }
        else {
            cout << "Incorrect. The correct answer is " << answers[i] << "." << endl;
        }
        char navigation;
        cout << "Enter 'P' to go to the Previous Question or 'N' to go to the Next Question (P/N): ";
        cin >> navigation;
        navigation = toupper(navigation);

        if (navigation == 'P' && i > 0) {
            i--; 
        } else if (navigation == 'N' && i < 4) {
            i++; 
        }
        
    }   

    cout << "\nYour total score is: " << score << "/5" << endl;

    return 0;
    
}
