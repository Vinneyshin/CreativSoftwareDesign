#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

string primeFactorization(unsigned int _number)
{
	int num = _number;
	string s, s1 = " x ";
	int a[100000];
	char b, c = 0;
	for (int i = 0; i < 100000; i++) a[i] = i;
	for (int i = 2; i <= num; i++) { while (num%i == 0) { c++; num /= i;}
		if (c != 0) s = s + to_string(a[i]) + "^" + to_string(a[c]);
		c = 0;
		if (s != "\0" && num % (i + 1) == 0) s += s1;
	}
	return s;
}
int main(int argc, char** argv) {
	if (argc < 1) return -1;
	unsigned int number;
	sscanf(argv[1], "%u", &number);
	cout << primeFactorization(number) << endl;
	return 0;
}
