#include "minesweeper.h"
using namespace std;

Minesweeper::Minesweeper(size_t row, size_t column) {
    mRow = row;
    mColumn = column;
}

bool Minesweeper::setMap() {
    string line;

    for (size_t i = 0; i < mRow; ++i)
    {
        getline(cin, line);
        if (line.size() > mColumn)
        {
            return false;
        }
        mRawMap.push_back(line);
    }

    return true;
}

bool Minesweeper::calMine(size_t _x, size_t _y){
     // calMine은 mRawMap에서 *가 있는지 확인하고
     // 0으로 초기화된 mCalMap에 1씩 더해주기.
    // pair 로
    vector<pair<size_t, size_t> > minePos;
    for (size_t i = 0; i < mRow; i++)
    {
        for (size_t j = 0; j < mColumn; j++)
        {
            if(mRawMap[i][j] == '*')
            {
                minePos.push_back(make_pair(i, j));
                
            }
        }
        
    }
    
}

void Minesweeper::calMap(){
    mCalMap.resize(mRow, vector<char>(mColumn, '0'));

    for (size_t i = 0; i < mRow; i++)
    {
        for (size_t j = 0; j < mColumn; j++)
        {
            calMine(i, j);
        }
    }
    
    for (size_t i = 0; i < mRow; i++)
    {
        for (size_t j = 0; j < mColumn; j++)
        {
            cout << mCalMap[i][j];
        }
        cout << endl;
    }
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

