#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
string RadixNotation(unsigned int number, unsigned int radix) {
	char a[100];
	string s;
	for (int i = 0; i < 10; i++)	a[i] = '0' + i;
	for (int i = 10; i <= 36; i++)	a[i] = 'a' + (i - 10);
	while (true)
	{
		if (number == 0) break;
		s = a[number%radix] + s;
		number /= radix;
	}
	return s;
}
int main(int argc, char** argv) {
	if (argc < 2) return -1;
	unsigned int radix;
	sscanf(argv[1], "%u", &radix);
	if (radix < 2 || radix>36) return -1;
	for (int i = 2; i < argc; ++i) {
		unsigned int number;
		sscanf(argv[i], "%u", &number);
		cout << RadixNotation(number, radix) << endl;
	}
	return 0;
}
