// binary_search.h
// Implement your binary_search.cc

#ifndef __hw03__binary_search__
#define __hw03__binary_search__

#include <iostream>
using namespace std;

class BinarySearch
{
private:
    int *mArray;
    int mArrayCount;
    int recursiveBsearch(int* arr, int target, int low, int high);
    void sortArray(); // you can reuse your previous sort assignment
    
public:
    BinarySearch();
    BinarySearch(int *_array, int _arrayCount);
    ~BinarySearch();
    int getIndex(int _element) ; // return -1 when element doesn't exist
};

#endif