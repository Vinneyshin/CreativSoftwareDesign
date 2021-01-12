#include "omok.h"

Omok::Omok() : width_(GROUND_SIZE), height_(GROUND_SIZE), turn_(NOBODY) 
{
    for (size_t i = 0; i < GROUND_SIZE; i++)
    {
        for (size_t j = 0; j < GROUND_SIZE; j++)
        {
            map_[i][j] = '.';
        }
    }
}

int Omok::Put(int row, int column)
{
    if (row < -1 ||
        row > (GROUND_SIZE - 1) || 
        column < -1 || 
        column > (GROUND_SIZE - 1) ||
        map_[row][column] != '.')
    {
        cout << "Cannot be placed there" << endl;
        return turn_;
    }

    if (turn_ == WHITE)
    {
        map_[row][column] = 'X';
        turn_ = BLACK;
    }
    // turn_ == BLACK or turn_ == NOBODY
    else
    {
        map_[row][column] = 'O';
        turn_ = WHITE;
    }

    return turn_;
}

void Omok::IsOmok(int *winner) const
{
    
}

std::ostream &operator<<(ostream &os, const Omok &omok)
{
    for (size_t i = 0; i < GROUND_SIZE; i++)
    {
        for (size_t j = 0; j < GROUND_SIZE; j++)
        {
            os << omok.map_[i][j] << " ";
        }
        os << endl;
    }
    return os;
}