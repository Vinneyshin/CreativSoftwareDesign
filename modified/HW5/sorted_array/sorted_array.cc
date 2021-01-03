#include "sorted_array.h"

SortedArray::SortedArray() {

}

SortedArray::~SortedArray() {

}

void SortedArray::AddNumber(int num) {
    numbers_.push_back(num);
}

vector<int> SortedArray::GetSortedAscending() const {
    
    vector<int> temp = numbers_;
    sort(temp.begin(), temp.end());
    
    return temp;
}

vector<int> SortedArray::GetSortedDescending() const {
    vector<int> temp = numbers_;
    sort(temp.begin(), temp.end(), greater<int>());
    return temp;
}

int SortedArray::GetMax() const {
    return GetSortedDescending()[0];
}

int SortedArray::GetMin() const {
    return GetSortedAscending()[0];
}
