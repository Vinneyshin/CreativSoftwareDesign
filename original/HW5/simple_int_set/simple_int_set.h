// simple_int_set.h
// Implement your simple_int_set.cc

#ifndef __hw05__simple_int_set__
#define __hw05__simple_int_set__
#include <set>

class SimpleIntSet
{
private:
   	static std::set<int> Set;
    
public:
	SimpleIntSet();
	~SimpleIntSet();
	
	static std::set<int> SetIntersection(const std::set<int>& set0, const std::set<int>& set1);
    static std::set<int> SetUnion(const std::set<int>& set0, const std::set<int>& set1);
    static std::set<int> SetDifference(const std::set<int>& set0, const std::set<int>& set1);
    static void printSet();
};

#endif
