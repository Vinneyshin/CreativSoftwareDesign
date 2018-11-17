#include "sorted_array.h"

using namespace std;

SortedArray::SortedArray()
{
}


SortedArray::~SortedArray()
{
}

void SortedArray::AddNumber(int num)
{
	numbers_.push_back(num);

	int temp;
	for (int i = 0; i < numbers_.size() - 1; i++) {
		for (int j = i + 1; j < numbers_.size(); j++) {
			if (numbers_[i] > numbers_[j]) {
				temp = numbers_[i];
				numbers_[i] = numbers_[j];
				numbers_[j] = temp;
			}
		}
	}
}

vector<int> SortedArray::GetSortedAscending() const
{
	return numbers_;
}

vector<int> SortedArray::GetSortedDescending() const
{
	vector<int> descendingvec;
	descendingvec.assign(numbers_.rbegin(), numbers_.rend());
	return descendingvec;
}

int SortedArray::GetMax() const
{
	return numbers_.back();
}

int SortedArray::GetMin() const
{
	return numbers_.front();
}

void SortedArray::printvector(vector<int> vec)
{
	vector<int>::iterator it;
	for (it = vec.begin(); it < vec.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}
