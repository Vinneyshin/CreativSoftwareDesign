#include "draw_shape.h"

Canvas::Canvas(size_t row, size_t col)
{
    row_ = row;
    col_ = col;
}

Canvas::~Canvas()
{
}

int Canvas::AddShape(const Shape &s)
{
    shapes_.push_back(s);
    // Return the index of the shape.
    return shapes_.size() - 1;
}

void Canvas::DeleteShape(int index)
{
    if (index >= shapes_.size())
        return;
    shapes_.erase(shapes_.begin() + index);
}

void Canvas::Draw(ostream &os)
{
    vector<vector<char> > map;
    map.resize(row_, vector<char>(col_, '.'));

    //Drawing each shape on map
    for (size_t i = 0; i < shapes_.size(); i++)
    {
        Shape& shape = shapes_.at(i);
        if (shape.type == RECTANGLE)
        {
            size_t starting_x = shape.x - (shape.width / 2);
            size_t starting_y = shape.y - (shape.height / 2);

            for (size_t k = 0; k < shape.height; k++)
            {
                for (size_t m = 0; m < shape.width; m++)
                {
                    map[starting_y + k][starting_x + m] = shape.brush;   
                }
            }
        }

        else if (shape.type == TRIANGLE_UP)
        {
            
        }
        else if (shape.type == TRIANGLE_DOWN)
        {
            
        }
        else
        {
            cout << "invalid type" << endl;
        }
    }

    Drawmap(map);
}

void Canvas::Dump(ostream &os)
{
    for (size_t i = 0; i < shapes_.size(); i++)
    {
        cout << i << " ";

        switch (shapes_[i].type)
        {
        case RECTANGLE:
            cout << "rect"
                 << " ";
            break;

        case TRIANGLE_UP:
            cout << "tri_up"
                 << " ";
            break;

        case TRIANGLE_DOWN:
            cout << "tri_down"
                 << " ";
            break;

        default:
            cout << "non-type";
        }

        cout << shapes_[i].x << " " << shapes_[i].y << " " << shapes_[i].width << " " << shapes_[i].height << " " << shapes_[i].brush << endl;
    }
}

void Canvas::Drawmap(vector<vector<char> > map) {
    cout << " ";

    for (size_t i = 0; i < col_; i++)
        cout << i;

    cout << endl;

    for (size_t i = 0; i < row_; i++)
    {
        cout << i;
        for (size_t j = 0; j < col_; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}