#include "draw_shape2.h"

void Clear();

Canvas::Canvas(size_t row, size_t col)
{
    row_ = row;
    col_ = col;
    map_.assign(row_, vector<char>(col_, '.'));
}   

Canvas::~Canvas() {}

void Canvas::Clear()
{
    // 초기화
    for (size_t i = 0; i < row_; i++)
    {
        for (size_t j = 0; j < col_; j++)
        {
            map_[i][j] = '.';
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

void Canvas::Resize(size_t row, size_t col)
{
    map_.resize(row, vector<char>(col, '.'));

    // 아래 추가 이유는 주석 링크 확인
    for (size_t i = 0; i < row_; i++)
    {
        map_[i].resize(col, '.');
    }
    row_ = row;
    col_ = col;
    
    /*
    map_.resize(row_, vector<char>(col_, '.'));
    이건 잘 작동 안함
    https://stackoverflow.com/questions/65729229/how-to-resize-2d-vector/65729507#65729507
    내가 작성한 질문, 답변 참고하기
    */
}

Shape::Shape()
{
    type_ = "";
    x_ = -1;
    y_ = -1;   
    h_ = 0;
    w_ = 0;
    brush_ = '\0';
}
Shape::~Shape() {}

Rectangle::Rectangle()
{
    type_ = "rect";
}
Rectangle::~Rectangle() {}

void Rectangle::Draw(Canvas *canvas) const
{
    int x = this->x_, y = this->y_, w = this->w_ ,h = this->h_;
    char brush = this->brush_;
    for (size_t i = 0; i < h; i++)
    {
        for (size_t j = 0; j < w; j++)
        {
            canvas->Draw(y + i, x + j, brush);
        }
    }
}

void UpTriangle::Draw(Canvas *canvas) const
{

}

void DownTriangle::Draw(Canvas *canvas) const
{

}

void Diamond::Draw(Canvas *canvas) const
{

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