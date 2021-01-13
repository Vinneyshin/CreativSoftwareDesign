#include "point2d.h"

Point::Point()
{
	x_ = 0;
	y_ = 0;
}

Point::Point(const Point &p)
{
	x_ = p.x_;
	y_ = p.y_;
}

Point::Point(int x, int y)
{
	x_ = x;
	y_ = y;
}

Point Point::operator-()
{
	x_ = -x_;
	y_ = -y_;
	return Point(x_, y_);
}

Point operator+(const Point &lhs, const Point &rhs)
{
	return Point(lhs.x_ + rhs.x_, lhs.y_ + rhs.y_);
}

Point operator-(const Point &lhs, const Point &rhs)
{
	return Point(lhs.x_ - rhs.x_, lhs.y_ - rhs.y_);
}

Point operator*(const Point &lhs, const Point &rhs)
{
	return Point(lhs.x_ * rhs.x_, lhs.y_ * rhs.y_);
}

std::ostream &operator<<(std::ostream &os, const Point &point)
{
	os << "(" << point.x_ << ", " << point.y_ << ")";

	return os;
}