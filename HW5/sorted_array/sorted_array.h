#include <iostream>
#include <vector>

using namespace std;

class SortedArray
{
public:
	SortedArray();
	~SortedArray();
	void AddNumber(int num);

	vector<int> GetSortedAscending() const;
	vector<int> GetSortedDescending() const;

	int GetMax() const;
	int GetMin() const;

	void printvector(vector<int> vec);

private:
	vector<int> numbers_;
};

