#include "simple_int_set.h"

struct Cmp {
    bool operator()(const int lhs, const int rhs) const
    {
        return lhs == rhs;
    }
};

void SimpleIntSet::SetPrint(const set<int>& _set)
{
    cout << "{ ";
    for (set<int>::iterator it = _set.begin(); it != _set.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << "}" << endl;
}

set<int> SimpleIntSet::SetUnion(const set<int>& set0, const set<int>& set1)
{
    set<int> resultSet(set0);
    for (set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
    {
        resultSet.insert(*it);
    }
    return resultSet;
}

set<int> SimpleIntSet::SetDifference(const set<int>& set0, const set<int>& set1)
{   
    set<int> resultSet(set0);
    for (set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
    {
        resultSet.erase(*it);
    }
    return resultSet;
}

set<int> SimpleIntSet::SetIntersection(const set<int>& set0, const set<int>& set1)
{
    set<int> resultSet;

    for (set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
    {
        set<int>::iterator inter_it = set0.find(*it);    
        if(inter_it != set0.end())
        {
            resultSet.insert(*inter_it);
        }
    }
    return resultSet;
}