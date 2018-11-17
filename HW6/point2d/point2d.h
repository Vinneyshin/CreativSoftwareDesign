#ifndef __hw06__point2d__
#define __hw06__point2d__
#define PLUS 1
#define MINUS 2
#define MULTI 3
#define ERROR 0
#include <string>
#include <vector>


struct Point {
	std::vector<std::string> inputs;
	int x_, y_;
	std::string string_;
	
	Point();
	Point(const Point& p);
	Point(int c);
	Point(std::string c_, int x, int y);
	Point(int X, int Y);
};

Point operator+(const Point& lhs, const Point& rhs);
Point operator-(const Point& lhs, const Point& rhs);
Point operator*(const Point& lhs, const Point& rhs);

#endif
