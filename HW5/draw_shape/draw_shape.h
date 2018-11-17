#ifndef __hw05__draw_shape__
#define __hw05__draw_shape__
#include <iostream>
#include <vector>
enum { RECTANGLE, TRIANGLE_UP, TRIANGLE_DOWN };
enum { ERROR_OUT_OF_CANVAS = -1, ERROR_INVALID_INPUT = -2 };

struct Shape {
	int type;
	int x, y;
	int width, height;
	char brush;
};

class Canvas {
	public:
		Canvas(size_t row, size_t col);
		~Canvas();
		
		int AddShape(const Shape &s);
		void DeleteShape(int index);
		void Draw(std::ostream& os);
		void Dump(std::ostream& os);
	
	private:
		size_t _row, _col;
		
		std::vector<std::vector<char> > canvas;
		std::vector<Shape> shapes_;
};

#endif
