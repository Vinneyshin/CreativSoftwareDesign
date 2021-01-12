#include "omok.h"

Omok::Omok() : width_(GROUND_SIZE), height_(GROUND_SIZE), turn_(NOBODY)
{
    min_row = GROUND_SIZE - 1;
    max_row = 0;

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

    // IsOmok에서 min_row 에서 max_row까지 최대한 효율적으로 탐색하기 위해서
    if (min_row > row)
    {
        min_row = row;
    }

    if (max_row < row)
    {
        max_row = row;
    }
    return turn_;
}

void Omok::IsOmok(int *winner) const
{
    char symbol;

    int previous_turn = turn_;
    
    if (previous_turn == WHITE)
    {
        // 'O' stands for BLACK
        // previous turn was WHITE's therefore, symbol should be BLACK's
        symbol = 'O';
    }
    else
    {  
        // Likewise, symbol should be WHITE's
        symbol = 'X';
    }

    for (int row = min_row; row < max_row; row++)
    {
        for (int column = 0; column < GROUND_SIZE - 1; column++)
        {
            if (symbol == map_[row][column])
            {
                int cnt = 1;
                //Find to the right
                if (column + 4 < GROUND_SIZE && map_[row][column + 4] == symbol)
                {
                    ++cnt;
                    int i = 3;
                    while (i && map_[row][column + i] == symbol)
                    {
                        ++cnt;
                        --i;
                    }
                }
                //Find to the diagonal bottom right
                else if (column + 4 < GROUND_SIZE && row + 4 < GROUND_SIZE && map_[row + 4][column + 4] == symbol)
                {
                    ++cnt;
                    int i = 3;
                    while (i && map_[row + i][column + i] == symbol)
                    {
                        ++cnt;
                        --i;
                    }
                }
                //Find to the bottom
                else if (row + 4 < GROUND_SIZE && map_[row + 4][column] == symbol)
                {
                    ++cnt;
                    int i = 3;
                    while (i && map_[row + i][column] == symbol)
                    {
                        ++cnt;
                        --i;
                    }
                }
                //Find to the Left
                else if (column - 4 > 0 && map_[row][column - 4] == symbol)
                {
                    ++cnt;
                    int i = 3;
                    while (i && map_[row][column + i] == symbol)
                    {
                        ++cnt;
                        --i;
                    }
                }

                if (cnt == 5)
                {
                    if (symbol == 'O')
                    {
                        *winner = BLACK;
                    }
                    else
                    {
                        *winner = WHITE;
                    }
                }
            }
        }
    }
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