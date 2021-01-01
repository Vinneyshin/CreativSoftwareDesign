#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const* argv[])
{
    int row, column;

    cin >> column >> row;

    vector<vector<char> > mapData_raw (row, vector<char>(column));
    
    
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            cout << mapData_mineCal [i][j];
        }
        cout << endl;
    }



    return 0;
}
