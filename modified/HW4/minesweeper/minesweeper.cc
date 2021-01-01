#include "minesweeper.h"
using namespace std;

Minesweeper::Minesweeper(size_t row, size_t column) {
    mRow = row;
    mColumn = column; 
    mMapData_raw.resize(row, vector<char>(column));
    mMapData_cal.resize(row, vector<char>(column, '0'));
}

Minesweeper::~Minesweeper(){
    
}

bool Minesweeper::setMap() {

    for (int i = 0; i < mRow; i++)
    {
        for (int j = 0; j < mColumn; j++)
        {
            cin >> mMapData_raw[i][j];
            
            if (mMapData_raw[i][j] == '*')
            {
                mMapData_cal[i][j] = '*';
                
                if(i - 1 >= 0 
                && j - 1 >= 0)
                    //left up
                    ++mMapData_cal[i - 1][j - 1];
                
                if(i - 1 >= 0)
                    //up
                    ++mMapData_cal[i - 1][j];
                
                if(i - 1 >= 0
                && j + 1 < mColumn)
                    //right up
                    ++mMapData_cal[i - 1][j + 1];

                if(j - 1 >= 0)
                    //left
                    ++mMapData_cal[i][j - 1];

                if(j + 1 < mColumn)
                    //right
                    ++mMapData_cal[i][j + 1];

                if(i + 1 < mRow
                && j - 1 >= 0)
                    //left down
                    ++mMapData_cal[i + 1][j - 1];

                if(i + 1 < mRow)
                    //down
                    ++mMapData_cal[i + 1][j];

                if(i + 1 < mRow
                && j + 1 < mColumn)
                    //right down
                    ++mMapData_cal[i + 1][j + 1];
            }
        }
    }

    for (int i = 0; i < mRow; i++)
    {
        for (int j = 0; j < mColumn; j++)
        {
            cout << mMapData_cal[i][j];
        }
        cout << endl;
    }
    return true;
}

bool Minesweeper::toggleMine(int _x, int _y) {
    return true;
}

size_t Minesweeper::row() const {
    return mRow;
}

size_t Minesweeper::column() const {
    return mColumn;
}

char Minesweeper::get (int _x, int _y) const {
    return mMapData_raw[_x][_y];
}

bool Minesweeper::setPlay() {
    return true;
}

bool Minesweeper::touchMap(int _x, int _y) {
    return true;
}

int Minesweeper::touchCount() const {
    return mTouchCount;
}

