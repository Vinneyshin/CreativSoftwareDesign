#include <iostream>
#include <assert.h>

using namespace std;

void Sort (int n_data, int* p_data){
	int temp;
	for (int i = 0; i < n_data -1; i++) {
		for (int j = i + 1; j < n_data; j++) {
			if (p_data[i] > p_data[j]) {
				temp = p_data[i];
				p_data[i] = p_data[j];
				p_data[j] = temp;
			}
		}
	}
}

int main() {
	int n_data;
	cin >> n_data;
	if(!(1 <= n_data))
		return 0;

	int* p_data = new int[n_data];

	for(int i = 0; i < n_data; i++) {
		cin >> p_data[i];
		if(!(p_data[i] <= 3000))
			return 0;
	}

	Sort(n_data, p_data);

	for (int i = 0; i < n_data; i++)
		cout << p_data[i] << " ";
	
	cout << endl;
	
	delete[] p_data;

	return 0;
}

