#include <iostream>
#include "omok.h"


int main(int argc, char const *argv[])
{
    int row, column;
    int winner = NOBODY;
    Omok gomoku;

    while (winner == NOBODY)
    {
        std::cin >> row >> column;
        gomoku.Put(row, column);
        std::cout << gomoku;
        gomoku.IsOmok(&winner);
    }

    cout << "Winner : " << (winner == BLACK ? "BLACK" : "WHITE") << endl;

    return 0;
}

