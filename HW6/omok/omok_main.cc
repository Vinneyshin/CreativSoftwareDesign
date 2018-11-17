#include "omok.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	vector<string> inputs;
	Omok stage;
	bool black_win;
	int x, y;
	
    do {
		cin >> x >> y;
		if(!stage.Put(x,y)) cout << "Can not be placed there" << endl;
	} while(!stage.IsOmok(&black_win));

	cout << stage << "Winner: ";
	if(black_win) cout << "Black player";
	else cout << "White player";

	cout << endl;
	
	return 0;
}
