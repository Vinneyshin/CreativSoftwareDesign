#include <iostream>
#include "sorted_array.h"
#include <bits/stdc++.h>
#include <cctype>

using namespace std;

ostream &operator<<(ostream &os, const vector<int> numbers)
{
    for (int i = 0; i < numbers.size(); i++)
        os << numbers[i] << " ";
    os << "\n";
    return os;
}

int main(int argc, char const *argv[])
{
    SortedArray sa;
    while (true)
    {
        string command;
       

        getline(cin, command);
        
        if (command == "quit")
            break;
        else if (command == "ascend")
            cout << sa.GetSortedAscending();
        else if (command == "descend")
            cout << sa.GetSortedDescending();
        else if (command == "max")
            cout << sa.GetMax() << endl;
        else if (command == "min")
            cout << sa.GetMin() << endl;
        else
        {
            istringstream iss(command);
            string token;
            while (getline(iss, token, ' '))
                sa.AddNumber(stoi(token));
        }
    }

    return 0;
}