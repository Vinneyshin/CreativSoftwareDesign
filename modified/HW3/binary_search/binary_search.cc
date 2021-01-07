#include "binary_search.h"



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


BinarySearch::BinarySearch(int *_array, int _arrayCount) {

    mArray = new int [_arrayCount];
    for (size_t i = 0; i < _arrayCount; i++)
    {
        mArray[i] = _array[i];
    }
    mArrayCount = _arrayCount;
    quickSort(mArray, 0, _arrayCount - 1);

}


BinarySearch::BinarySearch() {

}

BinarySearch::~BinarySearch() {

}
int BinarySearch::getIndex(int _element) {

    return recursiveBsearch(mArray, _element, 0, mArrayCount - 1);  
}

int BinarySearch::recursiveBsearch(int* arr, int target, int low, int high) {
    
    if(low > high)
    {
        return -1;
    }
    
    int mid = (low + high) / 2;
    
    if(arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target) 
    {
        return recursiveBsearch(arr, target, low, mid - 1);
    }
    else
    {
        return recursiveBsearch(arr, target, mid + 1, high);
    }
}

void BinarySearch::sortArray() {
    quickSort(mArray, 0, mArrayCount - 1);
}



