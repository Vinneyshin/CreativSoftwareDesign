#include <iostream>
#include <bits/stdc++.h>
#include "draw_shape.h"

//메인에서 에러 핸들링 하기보단 함수에게 그 권한을 이양하는게 더 OOP스럽지 않을까?

int main(int argc, char const *argv[])
{
    size_t row, column;

    cin >> column >> row;

    // Validating whether inputs are integer or not.
    if (cin.fail())
        return -1;

    // new line handling
    cin.ignore();

    Canvas cv(row, column);

    string command;

    while (true)
    {
        getline(cin, command);
        if (command.find("add") != string::npos)
        {
            //Makig "add rect x y height width brush" to "rect x y height width brush"
            command.erase(0, 4);

            Shape shape;
            vector<string> vs;
            istringstream iss(command);
            string token;

            while (getline(iss, token, ' '))
                vs.push_back(token);

            if (vs[0] == "rect")
            {
                shape.type = RECTANGLE;
                shape.x = stoi(vs[1]);
                shape.y = stoi(vs[2]);
                shape.width = stoi(vs[3]);
                shape.height = stoi(vs[4]);
                shape.brush = vs[5][0];

                /*
                 0 1 2 3 4 5 6 7 8 9
                0. . . . . . . . . .
                1. . . . . . . . . .
                2. . . . . . . . . .
                3. . . . . . . . . .
                4. . . . *** . . . .
                5. . . . *** . . . .  
                6. . . . *** . . . .
                7. . . . . . . . . .
                8. . . . . . . . . .
                */
            }

            else if (vs[0] == "tri_up")
            {
                shape.type = TRIANGLE_UP;
                shape.x = stoi(vs[1]);
                shape.y = stoi(vs[2]);
                shape.height = stoi(vs[3]);
                shape.brush = vs[4][0];

                //shape.x + shape.height - 1
                /*
                        --- << length == 3 == x + height - 1
                        #..      < 
                       ###.      <  ->  height == 3
                      #####      <

                */
               
            }

            else if (vs[0] == "tri_down")
            {
                shape.type = TRIANGLE_DOWN;
                shape.x = stoi(vs[1]);
                shape.y = stoi(vs[2]);
                shape.height = stoi(vs[3]);
                shape.brush = vs[4][0];

               
            }
            int check = cv.AddShape(shape);

            switch(check) {
                case ERROR_OUT_OF_CANVAS:
                    cout << "error out of canvas" << endl; break;
                case ERROR_INVALID_INPUT:
                    cout << "error invalid input" << endl; break;
                default:
                    break;
            }
        }

        else if (command.find("draw") != string::npos)
        {
            cv.Draw(cout);
        }

        else if (command.find("dump") != string::npos)
        {
            cv.Dump(cout);
        }

        else if (command.find("delete") != string::npos)
        {
            command.erase(0, 7);
            int index = stoi(command);
            cv.DeleteShape(index);
        }

        else if (command.find("quit") != string::npos)
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
