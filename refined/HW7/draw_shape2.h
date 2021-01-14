#include <iostream>

using namespace std;

class Canvas
{
public:
    Canvas(size_t row, size_t col);
    ~Canvas();
    // canvas 크기를 w * h 로 변경한다. 그려진 내용은 보존한다.
    void Resize(size_t w, size_t h);
    // (x, y) 위치에 문자를 그린다. 범위 밖의 x, y는 무시한다.
    bool Draw(int x, int y, char brush);
    // 그려진 내용을 모두 지운다. (‘.’으로 초기화)
    void Clear();

private:
    // 그려진 모양을 저장할 수 있도록 데이터멤버를 정의 (resize 가능에 주의)
    friend ostream &operator<<(ostream &os, const Canvas &c);
};

class Shape
{
public:
    virtual ~Shape();
    virtual void Draw(Canvas *canvas) const = 0;

protected:
    // 도형의 공통 속성 정의
};

class Rectangle : public Shape
{ /* 필요한 멤버를 정의 */
};

class UpTriangle : public Shape
{ /* 필요한 멤버를 정의 */
};

class DownTriangle : public Shape
{ /* 필요한 멤버를 정의 */
};

class Diamond : public Shape
{ /* 필요한 멤버를 정의 */
};

istream &operator>>(istream &is, Rectangle &r);
istream &operator>>(istream &is, UpTriangle &t);
istream &operator>>(istream &is, DownTriangle &d);
istream &operator>>(istream &is, Diamond &dm);