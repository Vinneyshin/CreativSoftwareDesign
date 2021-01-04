#include "draw_shape.h"

Canvas::Canvas(size_t row, size_t col) {
    row_ = row;
    col_ = col;
}

Canvas::~Canvas() {

}

int Canvas::AddShape(const Shape &s) {
    shapes_.push_back(s);
    // Return the index of the shape.
    return shapes_.size() - 1;
}

void Canvas::DeleteShape(int index) {
    if (index >= shapes_.size())
        return;
    shapes_.erase(shapes_.begin() + index);
}

void Canvas::Draw(ostream &os) {
    vector<vector<char> > map;
    map.resize(row_, vector<char>(col_, '.'));
    
    /* 
    Making map
    Ex)
    01234.....column
    1.........
    2.........
    3.........
    4.........
    .
    .
    .
    row
    */
    
    for (size_t i = 0; i < row_; i++)
        map[i][0] = i;
    
    for (size_t i = 0; i < col_; i++)
        map[0][i] = i;

}

void Canvas::Dump(ostream &os) {
    for (size_t i = 0; i < shapes_.size(); i++)
    {
        cout << i << " " << 
        shapes_[i].type <<
        shapes_[i].x <<
        shapes_[i].y <<
        shapes_[i].width <<
        shapes_[i].height <<
        shapes_[i].brush << endl;
    }
}