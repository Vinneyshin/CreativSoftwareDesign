#include "point2d.h"
#include <string>
#include <vector>
#include <string>

Point::Point() {}

Point::Point(const Point& p) {
	string_ = p.string_;
	x_ = p.x_;
	y_ = p.y_;
}

Point::Point(int c) {
	std::vector<std::string> inputs;
	string_ = std::to_string(c);
	x_ = c;
	y_ = c;
}

Point::Point(std::string c_, int x, int y) {
	string_ = c_;
	x_ = x;
	y_ = y;
}
	
Point::Point(int X, int Y) {
	string_ = ".";
	x_ = X;
	y_ = Y;
}

Point operator+(const Point& lhs, const Point& rhs) {
	int x = lhs.x_ + rhs.x_;
	int y = lhs.y_ + rhs.y_;
	return Point(x,y);
}

Point operator-(const Point& lhs, const Point& rhs) {
	int x = lhs.x_ - rhs.x_;
	int y = lhs.y_ - rhs.y_;
	return Point(x,y);
}

Point operator*(const Point& lhs, const Point& rhs) {
	int x = lhs.x_ * rhs.x_;
	int y = lhs.y_ * rhs.y_;
	return Point(x,y);
}

