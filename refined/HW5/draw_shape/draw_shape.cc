#include "draw_shape.h"

Canvas::Canvas(size_t row, size_t col)
{
    row_ = row;
    col_ = col;
    Draw(cout);
}

Canvas::~Canvas()
{
}

int Canvas::AddShape(const Shape &s)
{
    if (s.type == RECTANGLE && (s.width % 2 == 0 || s.height % 2 == 0))
    {
        return ERROR_INVALID_INPUT;
    }
    else if(s.type == RECTANGLE && (s.x + s.width / 2 > col_ - 1 || s.y + s.height / 2 > row_ - 1 || s.x - s.width / 2 < 0 || s.y - s.height / 2 < 0))
    {
        return ERROR_OUT_OF_CANVAS;
    }
    else if (s.type == TRIANGLE_UP && (s.x + (s.height - 1) > col_ - 1 || s.y + (s.height - 1) > row_ - 1 || s.x - (s.height - 1) < 0))
    {
        return ERROR_OUT_OF_CANVAS;
    }
    else if (s.type == TRIANGLE_DOWN && (s.x + (s.height - 1) > col_ - 1 || s.y - (s.height - 1) < 0 || s.x - (s.height - 1) < 0))
    {
        return ERROR_OUT_OF_CANVAS;
    }
    else
    {
        shapes_.push_back(s);
        // Return the index of the shape.
        return shapes_.size() - 1;
    }
}

void Canvas::DeleteShape(int index)
{
    if (index >= shapes_.size())
        return;
    shapes_.erase(shapes_.begin() + index);
}

void Canvas::Draw(ostream &os)
{
    vector<vector<char>> map;
    map.resize(row_, vector<char>(col_, '.'));

    //Drawing each shape on map
    for (size_t i = 0; i < shapes_.size(); i++)
    {
        Shape &shape = shapes_.at(i);

        if (shape.type == RECTANGLE)
        {
            size_t starting_x = shape.x - (shape.width / 2);
            size_t starting_y = shape.y - (shape.height / 2);

            for (int k = 0; k < shape.height; k++)
            {
                for (int m = 0; m < shape.width; m++)
                {
                    map[starting_y + k][starting_x + m] = shape.brush;
                }
            }
        }

        else if (shape.type == TRIANGLE_UP)
        {
            for (int k = 0; k < shape.height; k++)
            {
                //0 as a pivot, subtracting k and adding k
                for (int m = 0 - k; m <= 0 + k; m++)
                {
                    map[shape.y + k][shape.x + m] = shape.brush;
                }
            }
        }

        else if (shape.type == TRIANGLE_DOWN)
        {
            for (int k = 0; k < shape.height; k++)
            {
                //0 as a pivot, subtracting k and adding k
                for (int m = 0 - k; m <= 0 + k; m++)
                {
                    map[shape.y - k][shape.x + m] = shape.brush;
                }
            }
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
                 << " " << shapes_[i].x << " " << shapes_[i].y << " " << shapes_[i].width << " " << shapes_[i].height << " " << shapes_[i].brush << endl;
            break;

        case TRIANGLE_UP:
            cout << "tri_up"
                 << " " << shapes_[i].x << " " << shapes_[i].y << " " << shapes_[i].height << " " << shapes_[i].brush << endl;
            break;

        case TRIANGLE_DOWN:
            cout << "tri_down"
                 << " " << shapes_[i].x << " " << shapes_[i].y << " " << shapes_[i].height << " " << shapes_[i].brush << endl;
            break;

        default:
            cout << "non-type";
        }
    }
}

void Canvas::Drawmap(vector<vector<char>> map)
{
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