#include <iostream>
#include "draw_shape.h"

int main(int argc, char const *argv[])
{
    size_t row, column;
    
    cin >> column >> row;
    cin.ignore();

    string command;

    while (true)
    {
        getline(cin, command);
        if (command.find("add") != string::npos) {
            cout << "add" << endl;
        }
        else if (command.find("draw") != string::npos) {
            cout << "draw" << endl;
        }
        else if (command.find("dump") != string::npos) {
            cout << "dump" << endl;
        }
        else if (command.find("delete") != string::npos) {
            cout << "delete" << endl;
        }
        else if (command.find("quit") != string::npos) {
            cout << "quit" << endl;
        }
        else {
            cout << "invalid input" << endl;
        }
    }
    return 0;
}
