#include <iostream>
#include <list>
#include <iterator>
using namespace std;
//function for printing the elements in a list
void showlist(list <int> g)
{
    list <int> : : iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

int main()
{
    list <int> gqlist1, gqlist2;
    for (int i = 0; i < 10; ++i)
    {
        gqlist1.push_back(i * 2);
        gqlist2.push_front(i * 3);
    }
    cout << "\nList 1 (gqlist1) is: ";
    showlist(gqlist1);

    cout << "\nList 2 (gqlist2) is: ";
    showlist(gqlist2);

    cout << "\ngqlist1.front() : " << gqlist1.front()
    cout << "\ngqlist1.back() : " << gqlist1.back();
}
