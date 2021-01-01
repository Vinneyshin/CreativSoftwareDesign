#include<stdio.h>
#include<iostream>
using namespace std;

char a[55][55];

int main() {
	int x = 0, y = 0;
	int x_max = 0, y_max = 0;
	for (int i = 0; i <= 50; i++) { for (int j = 0; j <= 50; j++) a[i][j] = '.';
	}
	while (true) {
		cin >> x >> y;
		if (x_max <= x) x_max = x;
		if (y_max <= y) y_max = y;
		if (x == -1 || y == -1)return 0;
		a[y][x] = '*';
		for (int i = 0; i <= y_max; i++) {for (int j = 0; j <= x_max; j++) { cout << a[i][j];}	cout << "\n";
		}
	}
	return 0;
}
