#include <iostream>
#include <cstring>

using namespace std;

void make_magic_square(int n, int array_length, int ** raw_data) {

    int max_index_length = array_length - 1;
    int count = 0;
    int cursor_row = max_index_length;
    int cursor_column = max_index_length/2;

    /*
    aling number from 1 to n symmetrically
    for instance,
        0  0  9  0  0  
        0  8  0  6  0  
        7  0  5  0  3  
        0  4  0  2  0  
        0  0  1  0  0 
    */

    for (int i = 1; i <= n*n; i++)
    {
        raw_data[cursor_row - count][cursor_column + count] = i;
        count++;
        if(count == n) {
            cursor_row = cursor_row - 1;
            cursor_column = cursor_column - 1;
            count = 0;
        }
    }

    //cursor_row cursor_column re-initiallization
    cursor_row = max_index_length;
    cursor_column = max_index_length/2;

    //위 아래 숫자 옮기기

    for (int i = 0; i < (n-1)/2; i++)
    {
        cursor_row = max_index_length - i;
        for (int j = 0; j < i + 1; j++)
        {
            //시작점 설정하기 (왼쪽부터 시작)
            if(j == 0){
               cursor_column = max_index_length/2 - i;
            }
            raw_data[cursor_row - n][cursor_column + (2 * j)] = raw_data[cursor_row][cursor_column + (2 * j)];
            raw_data[i + n][cursor_column + (2 * j)] = raw_data[i][cursor_column + (2 * j)];
        }
    }
    
    //cursor_row cursor_column re-initiallization
    //반대로 함
    cursor_row = max_index_length/2;
    cursor_column = max_index_length;
    
    //좌 우 숫자 옮기기

    for (int i = 0; i < (n-1)/2; i++)
    {
        cursor_column = max_index_length - i;
        for (int j = 0; j < i + 1; j++)
        {
            //시작점 설정하기 (위 부터 시작)
            if(j == 0){
               cursor_row = max_index_length/2 - i;
            }
        
            raw_data[cursor_row + (2 * j)][cursor_column - n] = raw_data[cursor_row + (2 * j)][cursor_column];
            raw_data[cursor_row + (2 * j)][i + n] = raw_data[cursor_row + (2 * j)][i];
        }
    }

}

void print_magic_square(int n, int ** raw_data) {
    for (int i = (n - 1) / 2; i < (n - 1) / 2 + n; i++)
    {
        for (int j = (n - 1) / 2; j < (n - 1) / 2 + n; j++)
        {
            cout << raw_data[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    int n;

    cin >> n;

    if(n % 2 == 0 || 30 < n || n < 3) return 0;

    int array_length = 2*n - 1;

    //Dynamic memory allcation for making matrix

    int** raw_data = (int**)malloc(sizeof(int*) * array_length);
    
    for (int i = 0; i < array_length; i++)
    {
        raw_data[i] = (int*)malloc(sizeof(int) * array_length);
        memset(raw_data[i], 0, sizeof(int) * array_length);
    }
    
    make_magic_square(n, array_length, raw_data);
    print_magic_square(n, raw_data);

    for (int i = 0; i < array_length; i++) free(raw_data[i]);
    free(raw_data);

    return 0;
}
