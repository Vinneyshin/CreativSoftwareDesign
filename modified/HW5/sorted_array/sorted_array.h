#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SortedArray {
    public:
        SortedArray();
        ~SortedArray();
        void AddNumber(int num);

        vector<int> GetSortedAscending() const;
        vector<int> GetSortedDescending() const; 
        int GetMax() const;
        int GetMin() const; 
        
    private: 
        vector<int> numbers_;
};


