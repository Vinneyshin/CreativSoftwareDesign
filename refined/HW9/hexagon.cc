#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;

    while (T--)
    {
        int nData;
        
        cin >> nData;
        //parsing 
        int numbers[6];
        for (int i = 0; i < 6; i++)
        {
            numbers[5 - i] = nData % 10;
            nData = nData / 10;
        }

        //전체 정삼각형에서 바깥 삼각형 빼기
        int number_of_total_triangles = pow(numbers[0] + numbers[1] + numbers[5], 2);
        
        number_of_total_triangles -= pow(numbers[1], 2);
        number_of_total_triangles -= pow(numbers[3], 2);
        number_of_total_triangles -= pow(numbers[5], 2);

        cout << number_of_total_triangles << endl;
    }

    return 0;
}