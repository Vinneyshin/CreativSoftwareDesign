#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int Diffrentiate(string func,int c) {
	int check_neg = 0;
	int check_x = 0;
	int a = 1;
	int m = 1;
	int temp_m = 0;
	int temp_a = 0;

	for (int i = 0; i < func.size(); ++i) {
		if (func[i] == '-') {
			check_neg = 1;
		}
		if (func[i] == '^') {
			temp_m = temp_m * 10 + (int)(func[i + 1] - '0');
		}
		if (func[i] == 'x') {
			check_x = 1;
			if (i != 0 && isdigit(func[i - 1])) {
				if (check_neg) {
					for (int j = 1; j < i; ++j) {
						temp_a = temp_a * 10 + (int)(func[j] - '0');
					}
				}
				else
				{
					for (int j = 0; j < i; ++j) {
						temp_a = temp_a * 10 + (int)(func[j] - '0');
					}
				}
			}
		}
	}

	if (temp_a) a = temp_a;
	if (temp_m) m = temp_m;
	if (check_x) {
		if (check_neg) {
			return -(m*a*(pow(c, (m - 1))));
		}
		return m*a*(pow(c, (m - 1)));
	}
	else
	{
		return 0;
	}
	
}

int main() {
	
	while (true) {
		int sum = 0;
		vector<string> funcs;
		//get inputs
		string inputs_string;
		getline(cin >> ws, inputs_string);
		//string to vector<char>
		vector<char> inputs_vec(inputs_string.begin(),inputs_string.end());
		int c;
	
		if (inputs_string == "quit") {
			break;
		}
		cin >> c;
		vector<char> tmpvec;

		//inserting funcs
		for (vector<char>::iterator it = inputs_vec.begin(); it != inputs_vec.end(); ++it) {
			if (*(it) == '+') {
				string str(tmpvec.begin(), tmpvec.end());
				funcs.push_back(str);
				inputs_vec.erase(inputs_vec.begin(), it+1);
				it = inputs_vec.begin();
				tmpvec.clear();
			}
			tmpvec.push_back(*(it));
			if (it == inputs_vec.end() - 1) {
				string str(tmpvec.begin(), tmpvec.end());
				funcs.push_back(str);
			}
		}

		//diffrentiate
		for (int i = 0; i < funcs.size(); ++i) {
			sum += Diffrentiate(funcs[i], c);
		}

		cout << sum << endl;
	}
	return 0;
}
