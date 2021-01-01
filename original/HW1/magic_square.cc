#include <iostream>
#include <assert.h>

using namespace std;

/*void Initialize(int n_data, int** mabangjin) {
	for (int i = 0; i < n_data; i++) {
		for (int k = 0; k < n_data; k++) {
			mabangjin[i][k] = 0;
		}
	}
}*/

void Display(int n_data, int** mabangjin) {
	for (int i = 0; i < n_data; i++) {
		for (int k = 0; k < n_data; k++) {
			cout << mabangjin[i][k] << " ";
		}
		cout << endl;
	}
}

/*
void Calculate(int n_data, int** mabangjin) {
	int number = 1;
	int column = (n_data - 1) / 2;
	int row = n_data - 1;
	mabangjin[row][column] = number;

	for (int number = 1; number <= (n_data*n_data); number++){
		column++;
		row++;
		if ((n_data == column) && (n_data == row)) {
			mabangjin[row - 2][column - 1] = number;
		}
		else if (n_data == column) {
			mabangjin[row][0] = number;
		}
		else if (n_data == row) {
			mabangjin[0][column] = number;
		}
		else if (!(mabangjin[row][column] == 0)) {
			mabangjin[row - 2][column - 1] = number;
		}
		else {
			mabangjin[row][column] = number;
		}
	}
}*/

void Calculate(int n_data, int** mabangjin) {
	int row = 0; 
	int column = n_data / 2;
	for(int number = 1; number <= n_data*n_data; number++) {
			mabangjin[row][column] = number;
			row--;
			column--;
			if((number+1)%n_data == 1)
				row++;
			if (row<0)
				row = row + n_data;
			if (column<0)
				column = column + n_data;

	}
}

int main() {
	int n_data;

	cin >> n_data;
	
	if(!(3 <= n_data && n_data <= 30 && n_data % 2 == 1))
		return 0;

	int** mabangjin = new int*[n_data];

	for (int j = 0; j < n_data; j++) {
		mabangjin[j] = new int[n_data];
	}

//	Initialize(n_data, mabangjin);
	Calculate(n_data, mabangjin);
	Display(n_data, mabangjin);

	for (int i = 0; i < n_data; i++) {
		delete[] mabangjin[i];
	}

	delete[] mabangjin;
	return 0;
}
