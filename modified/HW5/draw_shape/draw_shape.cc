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
    shapes_.erase(shapes_.begin() + index);
}

void Canvas::Draw(ostream &os) {
    
}

void Canvas::Dump(ostream &os) {

}