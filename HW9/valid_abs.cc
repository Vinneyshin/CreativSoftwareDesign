#include <iostream>
#include <string>
using namespace std;

int main() {
	int number = 0;
	int i = 0;
	string inputs;
	cin >> number;
	getline(cin, inputs);
	bool* yesorno = new bool[number];
	while (i < number) {
		
		getline(cin, inputs);
		int left = 0;
		int right = 0;
		bool check = false;
		if (inputs.size() > 50 || inputs.size() < 2) {
			break;
		}
		for (int j = 0; j < inputs.size(); j++) {
			if (inputs[j] == '<') {
				left++;
			}
			else if (inputs[j] == '>') {
				right++;
			}
			else {
				check = true;
			}
		}
		if (check == true) {
			break;
		}
		yesorno[i] = (left == right);
		i++;

	}
	for (int i = 0; i < number; i++) {
		if (yesorno[i] == true) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}