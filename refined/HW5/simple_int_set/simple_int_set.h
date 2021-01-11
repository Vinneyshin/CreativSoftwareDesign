// simple_int_set.h
// Implement your simple_int_set.cc

#ifndef __hw03__simple_int_set__
#define __hw03__simple_int_set__

#define MAX_SIZE 1024

#include <iostream>
#include <set>

using namespace std;

class SimpleIntSet
{

public:
    static set<int> SetUnion(const set<int>& set0, const set<int>& set1);
    static set<int> SetDifference(const set<int>& set0, const set<int>& set1);
    static set<int> SetIntersection(const set<int>& set0, const set<int>& set1);
    static void SetPrint(const set<int>& set0);
};

#endif
