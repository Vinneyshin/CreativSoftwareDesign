#include <iostream>

using namespace std;


// 이미 정렬된 자료에 빠른건 Insertion Sort
// 앞자리 원소와 한번씩만 비교하면 되기 때문
// 퀵소트로 짜보기

void swap(int* left, int* right){
    int tmp = *left;
    *left = *right;
    *right = tmp;
}

int partition(int* array, int low, int high) {
    // Set the rightmost as a pivot
    int pivot = array[high];
    int i = (low - 1);

    for (size_t j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return i + 1;
    
}

void quickSort(int* array, int low, int high) {
    //"high" variable is rightmost
    //"low" variable is leftmost
    if(low < high)
    {
        int pi = partition(array, low, high); 
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int main(int argc, char const *argv[])
{
    int nData;
    cin >> nData;

    // nData should be larger than 0
    // nData's sign should be '+'
    if (nData < 1)
        return -1;

    int* array = new int[nData];

    // Get inputs
    for (size_t i = 0; i < nData; i++)
    {
        cin >> array[i];
        if (array[i] > 3000)
            return -1;
    }

    quickSort(array, 0, nData - 1);

    // Printing array
    for (size_t i = 0; i < nData; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;
    
    return 0;
}
