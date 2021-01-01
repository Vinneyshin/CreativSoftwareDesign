#include "binary_search.h"

BinarySearch::BinarySearch() {
    /* Implement Here. */
}

BinarySearch::BinarySearch(int *array, int array_count) {
    array_ = array;
    array_count_ = array_count;
}

BinarySearch::~BinarySearch() {
    /* Implement Here. */
}

// sort algorithm
void BinarySearch::SortArray() {
    int i, j, temp;
    for (i = 0; i < array_count_ - 1; i++) {
        for (j = 0; j < array_count_ - i - 1; j++) {
            if (array_[j] > array_[j + 1]) {
                temp = array_[j + 1];
                array_[j + 1] = array_[j];
                array_[j] = temp;
            }
        }
    }
}

// binary search algorithm
int BinarySearch::GetIndex(int element) {
    int left = 0, right = array_count_ - 1;
    int mid;
    while (left < right) {        
        mid = (left + right) / 2;
        if (element > array_[mid]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    if (element == array_[left]) {
        return left; // return index of given element
    } else {
        return -1; // return -1 if element is not in the array
    }
}
