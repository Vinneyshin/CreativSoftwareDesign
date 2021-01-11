#include <iostream>
#include <vector>
#include <string>
#include "minesweeper.h"

using namespace std;

int main(int argc, char const *argv[])
{
    size_t row, column;
    string command;
    Minesweeper minesweeper;
    bool isValid = true; 
    while (isValid)
    {
        getline(cin, command);

        if (command.find(":set") != string::npos)
        {
            command.erase(0, 4);
            // After erasing this command would be like "%d %d"
            istringstream iss(command);

            iss >> column >> row;

            minesweeper = Minesweeper(row, column);
            isValid = minesweeper.setMap();
            minesweeper.calMap();
        }
        else if (command.find(":toggle") != string::npos)
        {
            command.erase(0, 7);

            istringstream iss(command);
            // x stands for column and y stands for row.
           
            iss >> column >> row;

            isValid = minesweeper.toggleMine(row, column);
            minesweeper.calMap();
        }
        else if (command.find(":play") != string::npos)
        {
            bool isDead = false;
            istringstream iss;
            minesweeper.setPlay();
            
            while (!isDead)
            {
                
                getline(cin, command);

                if (command.find(":touch") != string::npos)
                {
                    command.erase(0, 6);
                    iss = istringstream(command);
                    iss >> column >> row;

                    isDead = minesweeper.touchMap(row, column);
                }
                else
                {
                    cout << "invalid input" << endl;
                }
            }
            cout << "DEAD(" << minesweeper.touchCount() << ")" << endl;
        }
        else if (command.find(":quit") != string::npos)
        {
            break;
        }
        else
        {
            cout << "invalid input" << endl;
        }
    }

    return 0;
}
