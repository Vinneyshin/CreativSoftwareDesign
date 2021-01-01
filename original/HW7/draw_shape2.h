#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Canvas {
	public:
		Canvas(size_t row, size_t col);
		~Canvas();
		void Resize (size_t w, size_t h);
		bool Draw(int x, int y, char brush);
		void Clear();
	private:
		size_t row_, col_;
		vector<string> s_;
		friend ostream& operator<<(ostream& os, const Canvas& c);
};

class Shape {
	public:
		virtual ~Shape();
		virtual void Draw(Canvas* canvas) const = 0;
		string type() {
			return type_;
		}
		int x() {
			return x_;
		}
		int y() {
			return y_;
		}
		int w() {
			return w_;
		}
		int h() {
			return h_;
		}
		char brush() {
			return brush_;
		}
	protected:
		int x_, y_, w_, h_;
		char brush_;
		string type_;
};

class Rectangle : public Shape {
	public:
		Rectangle() {}
	private:
		virtual void Draw(Canvas* canvas) const;
		friend istream& operator>>(istream& is, Rectangle& r);
};
class UpTriangle : public Shape {
	public:
		UpTriangle() {}
		virtual void Draw(Canvas* canvas) const;
	private:
		friend istream& operator>>(istream& is, UpTriangle& t);
};
class DownTriangle : public Shape {
	public:
		DownTriangle() {}
		virtual void Draw(Canvas* canvas) const;
	private:
		friend istream& operator>>(istream& is, DownTriangle& d);
};
class Diamond : public Shape {
	public:
		Diamond() {}
		virtual void Draw(Canvas* canvas) const;
	private:
		friend istream& operator>>(istream& is, Diamond& dm);
};

istream& operator>>(istream& is, Rectangle& r);
istream& operator>>(istream& is, UpTriangle& t);
istream& operator>>(istream& is, DownTriangle& d);
istream& operator>>(istream& is, Diamond& dm);
