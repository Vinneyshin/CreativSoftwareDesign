// simple_int_set.h
// Implement your simple_int_set.cc

#ifndef __hw03__simple_int_set__
#define __hw03__simple_int_set__

#define MAX_SIZE 1024

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class SimpleIntSet
{
private:
    int *mElements;
    int mElementCount;

    void sortElements(); // you can reuse your previous sort assignment
    SimpleIntSet();
    
public:
    SimpleIntSet(int *_elements, int _count);
    ~SimpleIntSet();
    
    int *elements() const { return mElements; } // return sorted array
    int elementCount() const { return mElementCount; };
    
    SimpleIntSet *unionSet(SimpleIntSet& _operand);
    SimpleIntSet *differenceSet(SimpleIntSet& _operand);
    SimpleIntSet *intersectSet(SimpleIntSet& _operand);
    
    void printSet();
};

#endif
