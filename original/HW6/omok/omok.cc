#include "omok.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> inputs;

Omok::Omok() : width_(19), height_(19), blacks_turn_(true) {
    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            stage_[i][j] = 0;
        }
    }
}

bool Omok::Put(int x, int y){
    if (x >= width_ || y >= height_ || x < 0 || y < 0) {
        return false;
    } else if (stage_[y][x] != 0) {
        return false; 
    } else {
        if (blacks_turn_) {
            stage_[y][x] = 1;
            blacks_turn_ = false;
        } else {
            stage_[y][x] = 2;
            blacks_turn_ = true;
        }
        recentX_ = x;
        recentY_ = y;
        return true;
    }
}

bool Omok::IsOmok(bool* is_winner_black) const {
    // row, column, up, down
    //int cnt_row = 1, cnt_col = 1, cnt_up = 1, cnt_down = 1;
    if (recentX_ > 18 || recentX_ > 18 || recentX_ < 0 || recentY_ < 0) {
        return false;
    }
    int cnt[4] = {1, 1, 1, 1};
    int col, row, i;
    int move_col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int move_row[8] = {1, 0, -1, 1, -1, 0, 1, -1};
    int recent_color = stage_[recentY_][recentX_];
    for (i = 0; i < 8; i++) {
        col = recentX_;
        row = recentY_;
        while (true) {
            col += move_col[i];
            row += move_row[i];
            if (col < 0 || row < 0 || col > 18 || row > 18) {
                break;
            }
            else if (stage_[row][col] == recent_color) {
                cnt[i % 4]++;
            } else {
                break;            
            }
        }
    }
    for (i = 0; i < 4; i++) {
        if (cnt[i] == 5) {
            if(recent_color == 1) {
                *is_winner_black = true;
                return true;
            } else {
                *is_winner_black = false;
                return true;
            }
        }
    }
    return false;
}

ostream& operator<<(std::ostream& os, const Omok& omok){
    for (int i = 0; i < omok.height_; i++) {
        for (int j = 0; j < omok.width_; j++) {
            switch (omok.stage_[i][j]) {
                case 0: {
                    os << ". ";
                    break;
                }
                case 1: {
                    os << "o ";
                    break;
                }
                case 2: {
                    os << "x ";
                    break;
                }
            }
        }
        os << endl;
    }
    return os;
}
