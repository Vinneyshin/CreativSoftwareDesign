#include <iostream>
#include <random>
using std::cout;
using std::cin;
using std::endl;

int monti(int strategy, int rep, int doors);
int f1(int);
int f2(int);
int f3(int);

int main() {
	int strategy;
	int rep, doors, success;
	cin >> strategy >> rep >> doors;
	success = monti(strategy, rep, doors);
	if(success==-1){
		exit(0);
	}
	cout.precision(3);
	cout << 100 * success / rep << "% (" << success << " / " << rep << ")" << endl;
	return 0;
}



int monti(int strategy, int rep, int doors) {
	int success = 0;
	if (strategy <= 0 || strategy > 3) {
		return -1;
	}
	static int (*f[3])(int) = {f1, f2, f3};
	for(int i=0;i<rep;++i){
		success += f[strategy-1](doors);
	}
	return success;
}

int getRandom(int limit){
	static std::random_device rd;
	static std::mt19937_64 rng(rd());
	std::uniform_int_distribution<int> dist(1, limit);
	return dist(rng);
}

int f1(int N) {
	return getRandom(N) == getRandom(N);
}

int f2(int N) {
	int gift = getRandom(N);
	int choice = getRandom(N);
	int host, last_choice;
	while ((host = getRandom(N)) == gift || host==choice);
	while ((last_choice = getRandom(N)) == choice || last_choice == host);
	return last_choice == gift;
}

int f3(int N) {
	int gift = getRandom(N);
	int choice = getRandom(N);
	int host, last_choice;
	while ((host = getRandom(N)) == gift || host == choice);
	while ((last_choice = getRandom(N)) == host);
	return last_choice == gift;
}
