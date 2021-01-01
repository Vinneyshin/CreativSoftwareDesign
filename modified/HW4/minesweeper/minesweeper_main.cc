#include <iostream>
#include <vector>
#include "minesweeper.h"

using namespace std;

int main(int argc, char const* argv[])
{
    int row, column;

    cin >> column >> row;


    Minesweeper ms(row, column);

    ms.setMap();



    return 0;
}
