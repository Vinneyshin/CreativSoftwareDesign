#ifndef minesweeper_h
#define minesweeper_h

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <array>

using namespace std;

class Minesweeper
{
public:
    ////////// 4-3-1 (7 score) //////////
    Minesweeper(size_t row, size_t column);
    Minesweeper();
    ~Minesweeper();
    
    // return false when input is incorrect
    
    bool setMap();
    bool toggleMine(size_t row, size_t column);
    
    // return map width, height, and char
    size_t row() const;
    size_t column() const;
    char get(size_t row, size_t column) const; // return ' ' if input is illegal
    
    ////////// 4-3-2 (3 score) //////////
    bool setPlay(); // return false when map is not set
    bool touchMap(size_t row, size_t column); // return true when dead
    void calMap();
    int touchCount() const;
    
private:
    // add private member variables and functions if it is needed.
    size_t mColumn;
    size_t mRow;
    size_t mTouchCount;
    vector<string> mRawMap;
    vector<vector<char> > mCalMap;

    bool calMine(size_t row, size_t column);
};

#endif /* minesweeper_h */
