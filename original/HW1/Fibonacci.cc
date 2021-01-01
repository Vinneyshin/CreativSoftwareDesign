#include <iostream>
#include <assert.h>
using namespace std;

int fibonacci(int nData)
{	
	
	if (nData == 1)
		return 1;
	else if (nData == 2)
		return 1;
	else
		return fibonacci(nData - 1) + fibonacci(nData - 2);
}

int main() {
	int nData;
	cin >> nData;
	if (!(1 <= nData && nData <= 45))
		return 0;
	for (int i = 1; i <= nData; i++){
		cout << fibonacci(i) << " ";
	}
	cout << endl;
	return 0;
}


