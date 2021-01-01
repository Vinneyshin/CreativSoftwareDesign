#include "draw_shape.h"
#include <vector>
#include <string>
using namespace std;

Canvas::Canvas(size_t row, size_t col) {
	_row = row;
	_col = col;
}

Canvas::~Canvas() {
	
}
		
int Canvas::AddShape(const Shape &v) {
	if(v.x < 0 || v.x >= _col || v.y < 0 || v.y >= _row) return ERROR_OUT_OF_CANVAS;
	else if(v.type == TRIANGLE_DOWN && (v.x-v.height < -1 || (v.x+v.height) > _col || (v.y-v.height) < -1))
		return ERROR_OUT_OF_CANVAS;
	else if(v.type == TRIANGLE_UP && (v.x-v.height < -1 || (v.x+v.height) > _col || (v.y+v.height) > _row)) 
		return ERROR_OUT_OF_CANVAS;
	else if(v.type == RECTANGLE && (v.x + (v.width/2) >= _col || v.x - (v.width/2) < 0 || v.y + (v.height/2) >= _row || v.y + (v.height/2) < 0)) 
		return ERROR_OUT_OF_CANVAS;
	else if(v.type == RECTANGLE && (v.width % 2 == 0 || v.height % 2 == 0)) 
		return ERROR_INVALID_INPUT;
	else {
		shapes_.push_back(v);
		return shapes_.size()-1;
	}
}

void Canvas::DeleteShape(int index) {
	if(index >= shapes_.size()) return;
	
	shapes_.erase(shapes_.begin() + index);
	return;
}

void Canvas::Draw(ostream& os) {
	int iterator_x=0, iterator_y=0;
	for(int i=0;i<=_row;i++) {
		vector<char> elements;
		elements.resize(_col+1);
		canvas.push_back(elements);
		
		for(int j=0;j<=_col;j++) {
			if(i>10) iterator_y = i%10;
			if(j>10) iterator_x = j%10;
			else if(i<=10 && j<=10) {
				iterator_y = i;
				iterator_x = j;
			}
			if(i==0 && j==0) canvas[i][j] = ' ';
			else if(i==0) canvas[i][j] = (char)(iterator_x+47);
			else if(j==0) canvas[i][j] = (char)(iterator_y+47);
			else canvas[i][j] = '.';
		}
	}
	
	for(int i=0;i<shapes_.size();i++) {
		switch(shapes_[i].type) {
			case TRIANGLE_DOWN:
				for(int j=0;j<shapes_[i].height;j++) {
					for(int k=0;k<2*j+1;k++)
						canvas[shapes_[i].y-j+1][shapes_[i].x-j+k+1] = shapes_[i].brush;
						
				}
				break;
			case TRIANGLE_UP:
				for(int j=0;j<shapes_[i].height;j++) {
					for(int k=0;k<2*j+1;k++)
						canvas[shapes_[i].y+j+1][shapes_[i].x-j+k+1] = shapes_[i].brush;
				} 
				break;
			case RECTANGLE:
				int key_y, key_x;
				key_y = (shapes_[i].height)/2;
				key_x = (shapes_[i].width)/2;
				for(int j=(shapes_[i].y-key_y+1);j<=(shapes_[i].y+key_y+1);j++) {
					for(int k=(shapes_[i].x-key_x+1);k<=(shapes_[i].x+key_x+1);k++)
						canvas[j][k] = shapes_[i].brush;
				}
				break;
			default: break;
		}
	}
	
	for(int i=0;i<=_row;i++) {
		for(int j=0;j<=_col;j++) {
			os << canvas[i][j];
		}
		os << endl;
	}
	
	return;
}

void Canvas::Dump(ostream& os) {
	for(int i=0;i<shapes_.size();i++) {
		switch(shapes_[i].type) {
			case TRIANGLE_UP:
				os << i << " tri_up " << shapes_[i].x << " " << shapes_[i].y << " " << shapes_[i].height << " " << shapes_[i].brush << endl; 
				break;
			case TRIANGLE_DOWN:
				os << i << " tri_down " << shapes_[i].x << " " << shapes_[i].y << " " << shapes_[i].height << " " << shapes_[i].brush << endl;		
				break;
			case RECTANGLE:
				os << i << " rect " << shapes_[i].x << " " << shapes_[i].y << " " << shapes_[i].width << " " << shapes_[i].height << " " << shapes_[i].brush << endl;
				break;
			default: break;
		}
	}
	
	return;
}
