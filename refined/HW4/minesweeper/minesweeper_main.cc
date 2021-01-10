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

    while (true)
    {
        getline(cin, command);

        if (command.find(":set") != string::npos)
        {
            command.erase(0, 4);
            // After erasing this command would be like "%d %d"
            istringstream iss(command);

            iss >> column >> row;

            minesweeper = Minesweeper(row, column);
            minesweeper.setMap();
            minesweeper.calMap();
        }
        else if (command.find(":toggle") != string::npos)
        {
            command.erase(0, 7);

            istringstream iss(command);
            // x stands for column and y stands for row.
            size_t x, y;

            iss >> x >> y;

            minesweeper.toggleMine(x, y);
            minesweeper.calMap();
        }
        else if (command.find(":play") != string::npos)
        {
            bool isDead = false;
            size_t x, y;
            istringstream iss;

            while (!isDead)
            {
                minesweeper.setPlay();
                getline(cin, command);

                if (command.find(":touch") != string::npos)
                {
                    command.erase(0, 6);
                    iss = istringstream(command);
                    iss >> x >> y;

                    isDead = minesweeper.touchMap(x, y);
                }
                else
                {
                    cout << "invalid input" << endl;
                }
            }
            cout << "DEAD(" << minesweeper.touchCount() << ")" << endl;
        }
        else if (command.find(":quit"))
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
