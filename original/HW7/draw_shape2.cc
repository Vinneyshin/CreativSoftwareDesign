#include "draw_shape2.h"

Canvas::Canvas(size_t row, size_t col) {
	row_ = row;
	col_ = col;
	for(int j = 0; j < col_; j++) {
		string a;
                for(int i = 0; i < row_; i++) {
                	a+='.';
                }
       	s_.push_back(a);
        }
}
Canvas::~Canvas(){
	s_.clear();
}
void Canvas::Resize (size_t w, size_t h) {
	row_ = w;
	col_ = h;
	s_.clear();
	for(int j = 0; j < col_; j++) {
                string a;
                for(int i = 0; i < row_; i++) { 
                        a+='.';
                }
        s_.push_back(a);
        }
}
bool Canvas::Draw(int x, int y, char brush) {
	if (x < 0 || x >= row_ || y < 0 || y >= col_) {
		return false;
	}
	else {
		s_[y][x] = brush;
		return true;
	}
}
void Canvas::Clear() {
	s_.clear();
	for(int j = 0; j < col_; j++) {
                string a;
                for(int i = 0; i < row_; i++) {
                        a+='.';
                }
        s_.push_back(a);
        }
}

ostream& operator << (ostream& os, const Canvas& c) {
	os << " ";
	for (int i = 0; i < c.row_; i++) {
		os << i%10;
	}
	os << endl;
        for (int i = 0; i < c.col_; i++) {
		os << i%10;
                for (int j = 0; j < c.row_; j++) {
                        os << c.s_[i][j];
                }
                os << endl;
        }
	return os;
}

Shape::~Shape() {}

void Rectangle::Draw(Canvas* canvas) const {
	for (int i = y_; i < y_+h_; i++) {
		for (int j = x_; j < x_+w_; j++) {
			canvas->Draw(j, i, brush_);
		}
	}	
}
void UpTriangle::Draw(Canvas* canvas) const {
	for (int i = 0; i < h_; i++) {
		for (int j = 0; j < 2*i+1; j++) {
			canvas->Draw(x_-i+j,y_+i, brush_);
		}
	} 
}
void DownTriangle::Draw(Canvas* canvas) const {
	for (int i = 0; i < h_; i++) {
		for (int j = 0; j < 2*i+1; j++) {
			canvas->Draw(x_-i+j, y_-i, brush_);
		}
	}
}
void Diamond::Draw(Canvas* canvas) const {
        for (int i = 0; i < h_; i++) {
                for (int j = 0; j < 2*i+1; j++) {
                        canvas->Draw(x_-i+j, y_+i, brush_);
                }
        }
	for (int i = 0; i <= h_; i++) {
                for (int j = 0; j < 2*i+1; j++) {
                        canvas->Draw(x_-i+j, y_+2*h_-i, brush_);
                }
        }	
}

istream& operator>>(istream& is, Rectangle& r) {
	is >> r.x_ >> r.y_ >> r.w_ >> r.h_ >> r.brush_;
	r.type_ = "rect";
	return is;
}
istream& operator>>(istream& is, UpTriangle& t) {
	is >> t.x_ >> t.y_ >> t.h_ >> t.brush_;
	t.type_ = "tri_up";
	return is;
}
istream& operator>>(istream& is, DownTriangle& d) {
	is >> d.x_ >> d.y_ >> d.h_ >> d.brush_;
	d.type_ = "tri_down";
	return is;
}
istream& operator>>(istream& is, Diamond& dm) {
	is >> dm.x_ >> dm.y_ >> dm.h_ >> dm.brush_;
	dm.type_ = "diamond";
	return is;
}

