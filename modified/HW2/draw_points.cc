#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    //initialization
    int row, column;
    int max_row = -1;
    int max_column = -1;

    //matrix[row][column] == matrix[y][x]
    char matrix[101][51];

    for (int i = 0; i < 101; i++)
    {
        memset(matrix[i], '.', 51 * sizeof(char));
    }

    while (true)
    {
        //(x,y) format
        cin >> column >> row;

        // if column or row has "-" sign, "break" the loop.
        if (!(0 <= column && column <= 50)) break;
        if (!(0 <= row && row <= 100)) break;
        
        if (max_column < column)
            max_column = column;
        
        if (max_row < row)
            max_row = row;


        matrix[row][column] = '*';


        //printing the matrix
        for (int row = 0; row <= max_row; row++)
        {
            for (int column = 0; column <= max_column; column++)
            {
                cout << matrix[row][column];
            }
            cout << endl;
        }
    }

    return 0;
}
