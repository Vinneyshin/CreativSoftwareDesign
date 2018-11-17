#include<iostream>

#include<stdlib.h>

#include<iomanip>



#define CORRECT true

#define WRONG false



using namespace std;

enum Strategy { KEEP = 1, CHANGE = 2, RANDOM = 3 };

void MontyHall(int _strategy, int& _corrects) {

	bool doors[3];	//door0, door1, door2

	const int presentdoor = rand() % 3;

	for (int i = 0; i<3; i++) {

		if (i != presentdoor) doors[i] = WRONG;

		else doors[i] = CORRECT;	//present

	}



	int chosendoor = rand() % 3;



	if (chosendoor == presentdoor) {

		if (_strategy == RANDOM) { _strategy = (rand() % 2) + 1; }

		if (_strategy == KEEP) { _corrects++; }


	}

	else {

		if (_strategy == RANDOM) { _strategy = (rand() % 2) + 1; }

		if (_strategy == CHANGE) { _corrects++; }
	}
}


int main() {

	int STG;

	int tms;

	int crts = 0;

	cin >> STG;

	if (STG != KEEP&&STG != CHANGE&&STG != RANDOM) return 0;

	cin >> tms;

	if (tms <= 0) return 0;



	srand(time(NULL));

	int turn = 0;

	while (turn++ != tms) {

		MontyHall(STG, crts);

	}



	cout << fixed << setprecision(1) << (double)crts / tms * 100 << "% " << "(" << crts << "/" << tms << ")" << endl;



	return 0;

}



