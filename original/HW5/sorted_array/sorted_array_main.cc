#include <vector>
#include <iostream>
#include <string>
#include "sorted_array.h"

using namespace std;

bool SortedArrayOperation(SortedArray * sorted_array) {

	string inputs;


	getline(cin, inputs);

	if (inputs == "quit") {
		return false;
	}
	else if (inputs == "ascend") {
		sorted_array->printvector(sorted_array->GetSortedAscending());
	}
	else if (inputs == "descend") {
		sorted_array->printvector(sorted_array->GetSortedDescending());
	}
	else if (inputs == "max") {
		cout << sorted_array->GetMax() << endl;
	}
	else if (inputs == "min") {
		cout << sorted_array->GetMin() << endl;
	}
	else {
		int number = -1;

		for (int i = 0; i < inputs.size(); ++i)
		{
			char c = inputs[i];

			if (isdigit(c))
			{
				int num = (int)c - (int)'0';
				if (number < 0) number = num;
				else number = number * 10 + num;
			}
			else
			{
				sorted_array->AddNumber(number);
				number = -1;
			}
		}
		sorted_array->AddNumber(number);
	}


}


int main() {
	SortedArray* sorted_array = new SortedArray();

	while (SortedArrayOperation(sorted_array));

	return 0;

}