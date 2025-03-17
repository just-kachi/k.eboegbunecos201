#include <iostream>
using namespace std;

string whois(const string &name)
{
    if (name == "Ebuka" || name == "ebuka" || name == "EBUKA" || name == "chukwuebuka" || name == "Nnaji" || name == "Thierry" || name == "thierry" || name == "THIERRY" || name == "NNAJI" || name == "nnaji")
    {
        cout << name << " is a pussy." << endl;
    }
    else
    {
        cout << name << " is a good one." << endl;
    }
};

int main()
{
    string name;
    cout << "Enter your name: ";
    cin >> name;
    whois(name);
}