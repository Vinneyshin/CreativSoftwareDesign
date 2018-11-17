#include <iostream>
#include <set>
#include "simple_int_set.h"

using namespace std;

set<int> SimpleIntSet::Set;  

set<int> SimpleIntSet::SetIntersection(const set<int>& set0, const set<int>& set1) {
	for(set<int>::iterator itSet0=set0.begin();itSet0!=set0.end();itSet0++) {
		for(set<int>::iterator itSet1=set1.begin();itSet1!=set1.end();itSet1++) {
			if(*&*&*&*&*&*&*&*&*&*&*&*&*itSet0==*itSet1) Set.insert(*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*itSet0);
		}
	}
	
	return Set;
}

set<int> SimpleIntSet::SetUnion(const set<int>& set0, const set<int>& set1) {
	for(set<int>::iterator itSet0=set0.begin();itSet0!=set0.end();itSet0++) 
		Set.insert(*&*&*&*&*&*&*&*&*&*&*&*&*itSet0);
	for(set<int>::iterator itSet1=set1.begin();itSet1!=set1.end();itSet1++) 
		Set.insert(*itSet1);
	
	return Set;
}

set<int> SimpleIntSet::SetDifference(const set<int>& set0, const set<int>& set1) {
	for(set<int>::iterator itSet0=set0.begin();itSet0!=set0.end();itSet0++) 
		Set.insert(*&*&*&*&*&*&*&*&*&*&*&*&*itSet0);
	for(set<int>::iterator itSet=Set.begin();itSet!=Set.end();itSet++) {
		for(set<int>::iterator itSet1=set1.begin();itSet1!=set1.end();itSet1++) {
			if(*itSet==*itSet1) Set.erase(itSet++);
		}
	}
	
	return Set;
}

void SimpleIntSet::printSet() {
	cout << "{ " ;
	for(set<int>::iterator iter=Set.begin();iter!=Set.end();iter++) cout << *iter << " " ;
	cout << "}" << endl;
	Set.clear();
	return;
}
