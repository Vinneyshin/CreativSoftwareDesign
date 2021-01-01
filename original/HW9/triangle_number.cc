#include <iostream>

using namespace std;

/*
int i = 0;
while (i < 45) {
i++;
int j = 0;
while (j < 45) {
j++;
int k = 0;
while (k < 45) {
k++;
if (triangle[i] + triangle[j] + triangle[k] == number) {
return true;
}
}
}
}
*/

bool isTriangle(int number, int * triangle) {
	int i = 0;
	while ( i < 45) {
			for (int j = 0; j < 45; j++) {
				for (int k = 0; k < 45; k++) {
					if (triangle[i] + triangle[j] + triangle[k] == number) {
						return true;
					}
				}
			}
			i++;
	}
	return false;	
}

int main() {
	int* triangle = new int[45];
	triangle[0] = 1;
	for (int i = 1; i < 45; i++) {
		triangle[i] = triangle[i - 1] + i + 1;
	}
	int number;
	cin >> number;
	int * numbers = new int[number];
	for (int i = 0; i < number; i++) {
		cin >> numbers[i];
	}
	for (int i = 0; i < number; i++) {
		cout << isTriangle(numbers[i], triangle) << endl;
	}
	return 0;
}