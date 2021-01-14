#include "draw_shape2.h"

void Clear();

Canvas::Canvas(size_t row, size_t col)
{
    row_ = row;
    col_ = col;
    Clear();
}   

void Canvas::Clear()
{
    // 초기화
    for (size_t i = 0; i < row_; i++)
    {
        for (size_t j = 0; j < col_; j++)
        {
            map_[row_][col_] = '.';
        }
    }
}

bool Canvas::Draw(int x, int y, char brush)
{
    if(x < 0 || y < 0 || x > col_ - 1 || y > row_ - 1)
    {
        return false;
    }
    map_[y][x] = brush;
    return true;
}

void Canvas::Resize(size_t w, size_t h)
{
    map_.resize(h, vector<char>(w, '.'));
}




istream &operator>>(istream &is, Rectangle &r)
{
    is >> r.x_ >> r.y_ >> r.w_ >> r.h_ >> r.brush_;
    return is;
}

istream &operator>>(istream &is, UpTriangle &t)
{
    is >> t.x_ >> t.y_ >> t.h_ >> t.brush_;
    return is;
}

istream &operator>>(istream &is, DownTriangle &d)
{
    is >> d.x_ >> d.y_ >> d.h_ >> d.brush_;
    return is;
}

istream &operator>>(istream &is, Diamond &dm)
{
    is >> dm.x_ >> dm.y_ >> dm.h_ >> dm.brush_;
    return is;
}

ostream &operator<<(ostream &os, const Canvas &c)
{
    os << " ";
    for (size_t i = 0; i < c.col_; i++)
    {
        os << i % 10;
    }
    os << endl;

    for (size_t i = 0; i < c.row_; i++)
    {
        cout << i % 10;
        for (size_t j = 0; j < c.col_; j++)
        {
            cout << c.map_[i][j];
        }
        cout << endl;
    }
    return os;
}