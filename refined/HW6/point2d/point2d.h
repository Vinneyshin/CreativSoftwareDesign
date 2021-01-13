#include <iostream>


struct Point
{
	int x_, y_; // 멤버 변수
	
	Point();
	Point(const Point &p);
	
	explicit Point(int c) : x_(c), y_(c) {};
	
	Point(int x, int y);
	Point operator-(); // 전위 - 연산자
};

Point operator+(const Point &lhs, const Point &rhs);
Point operator-(const Point &lhs, const Point &rhs);
Point operator*(const Point &lhs, const Point &rhs);

std::ostream &operator<<(std::ostream &os, const Point &point);