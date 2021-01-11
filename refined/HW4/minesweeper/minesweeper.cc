#include "minesweeper.h"
using namespace std;

Minesweeper::Minesweeper(size_t row, size_t column)
{
    mRow = row;
    mColumn = column;
}

Minesweeper::Minesweeper()
{
}

Minesweeper::~Minesweeper()
{
}

bool Minesweeper::setMap()
{
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

bool Minesweeper::calMine(size_t row, size_t column)
{
    bool isMine = false;

    /*
    이렇게 짜면 아마... 한번 넣을때 비교는 적게하지만
    하드코딩이 되기때문에 유지보수하기 어려울 것
    하지만 이 이상으로 예외사항이 존재하기 어려우니
    차라리 적은 예외상황일 경우엔 하드코딩하고 유지보수성을 희생하고
    속도를 올려도 될듯...?

    Original 버전에선 각 인덱스마다 8개씩 무조건 비교를 해야함
    (n*n) * 8의 형태
    refined에선
    (n*n) + 2의 형태
    상당히 속도가 빨라졌을것이라 생각. 
    */

    if (mRawMap[row][column] == '*')
    {
        isMine = true;
        if (row == 0)
        {
            if (column == 0)
            {
                //왼쪽 위 모서리일 때
                ++mCalMap[row + 1][column];
                ++mCalMap[row + 1][column + 1];
                ++mCalMap[row][column + 1];
            }
            else if (column == mColumn - 1)
            {
                //오른쪽 위 모서리일 때
                ++mCalMap[row][column - 1];
                ++mCalMap[row + 1][column - 1];
                ++mCalMap[row + 1][column];
            }
            else
            {
                //위 양측 모서리를 제외한 가에 넣을 때
                ++mCalMap[row][column - 1];
                ++mCalMap[row + 1][column - 1];
                ++mCalMap[row + 1][column];
                ++mCalMap[row + 1][column + 1];
                ++mCalMap[row][column + 1];
            }
        }
        else if (row == mRow - 1)
        {
            if (column == 0)
            {
                //왼쪽 아래 모서리일 때
                ++mCalMap[row - 1][column];
                ++mCalMap[row - 1][column + 1];
                ++mCalMap[row][column + 1];
            }
            else if (column == mColumn - 1)
            {
                //오른쪽 아래 모서리일 때
                ++mCalMap[row][column - 1];
                ++mCalMap[row - 1][column - 1];
                ++mCalMap[row - 1][column];
            }
            else
            {
                //양쪽 모서리를 맨 아래 가일 때
                ++mCalMap[row][column - 1];
                ++mCalMap[row - 1][column - 1];
                ++mCalMap[row - 1][column];
                ++mCalMap[row - 1][column + 1];
                ++mCalMap[row][column + 1];
            }
        }
        else
        {
            if (column == 0)
            {
                //왼쪽 가일때
                ++mCalMap[row - 1][column];
                ++mCalMap[row - 1][column + 1];
                ++mCalMap[row][column + 1];
                ++mCalMap[row + 1][column + 1];
                ++mCalMap[row + 1][column];
            }
            else if (column == mColumn - 1)
            {
                //오른쪽 가일 때
                ++mCalMap[row - 1][column];
                ++mCalMap[row - 1][column - 1];
                ++mCalMap[row][column - 1];
                ++mCalMap[row + 1][column - 1];
                ++mCalMap[row + 1][column];
            }
            else
            {
                //가운데일때
                ++mCalMap[row - 1][column];
                ++mCalMap[row - 1][column - 1];
                ++mCalMap[row][column - 1];
                ++mCalMap[row + 1][column - 1];
                ++mCalMap[row + 1][column];
                ++mCalMap[row + 1][column + 1];
                ++mCalMap[row][column + 1];
                ++mCalMap[row - 1][column + 1];
            }
        }
    }
    return isMine;
}

void Minesweeper::calMap()
{
    mCalMap.assign(mRow, vector<char>(mColumn, '0'));
    vector<pair<size_t, size_t>> minePos;

    for (size_t row = 0; row < mRow; row++)
    {
        for (size_t column = 0; column < mColumn; column++)
        {
            if(calMine(row, column))
            {
                minePos.push_back(make_pair(row, column));
            }
        }
    }

    while (!minePos.empty())
    {
        mCalMap[minePos.back().first][minePos.back().second] = '*';
        minePos.pop_back();
    }
    
    for (size_t row = 0; row < mRow; row++)
    {
        for (size_t column = 0; column < mColumn; column++)
        {
            cout << mCalMap[row][column];
        }
        cout << endl;
    }
}

bool Minesweeper::toggleMine(size_t row, size_t column)
{

    if (row < 0 || row > mRow - 1)
    {
        return false;
    }

    if (column < 0 || column > mColumn - 1)
    {
        return false;
    }

    if (mRawMap[row][column] == '*')
    {
        mRawMap[row][column] = '.';
        return true;
    }
    else
    {
        mRawMap[row][column] = '*';
        return true;
    }

    return false;
}

size_t Minesweeper::row() const
{
    return mRow;
}

size_t Minesweeper::column() const
{
    return mColumn;
}

char Minesweeper::get(size_t row, size_t column) const
{
    return mRawMap[row][column];
}

bool Minesweeper::setPlay()
{
    return true;
}

bool Minesweeper::touchMap(size_t row, size_t column)
{
    return true;
}

int Minesweeper::touchCount() const
{
    return mTouchCount;
}
