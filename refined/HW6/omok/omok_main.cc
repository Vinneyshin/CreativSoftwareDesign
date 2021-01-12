#include <iostream>
#include "omok.h"


int main(int argc, char const *argv[])
{
    int row, column;
    int winner = NOT_DETERMINED;
    Omok gomoku;

    while (winner == NOT_DETERMINED)
    {
        std::cin >> row >> column;
        gomoku.Put(row, column);
        std::cout << gomoku;
        gomoku.IsOmok(&winner);
    }

    cout << "Winner : " << (winner == BLACK ? "BLACK" : "WHITE") << endl;

    return 0;
}

