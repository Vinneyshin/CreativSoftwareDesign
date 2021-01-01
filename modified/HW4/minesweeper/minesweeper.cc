#include "minesweeper.h"
using namespace std;

bool Minesweeper::setMap(size_t row, size_t column, vector<vector<char> >& _map){
    
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            cin >> mMapData_raw [i][j];
            
            if (mMapData_raw[i][j] == '*')
            {
                mMapData_cal[i][j] = '*';
                //left_up
                if(i - 1 >= 0 && j - 1 >=0)
                    mMapData_cal[i - 1][j - 1]++;
                //up
                if(i - 1 >= 0 && j >= 0)
                    mMapData_cal[i - 1][j]++;
                //right_up
                if(i - 1 >= 0 &&)

            }
        }
    }

}

bool Minesweeper::toggleMine(int _x, int _y) {

}

size_t Minesweeper::width() const {
    return mWidth;
}

size_t Minesweeper::height() const {
    return mHeight;
}

char Minesweeper::get (int _x, int _y) const {
    return mMapData_raw[_x][_y];
}

bool Minesweeper::setPlay() {

}

bool Minesweeper::touchMap(int _x, int _y) {
    
}

int Minesweeper::touchCount() const {
    return mTouchCount;
}

