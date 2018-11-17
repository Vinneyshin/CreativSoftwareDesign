#include<stdio.h>
#include "minesweeper.h"
using namespace std;
 int playcnt = 0;
bool mineOperation(Minesweeper * _mineSweeper)
{
	string inputs;
	getline(cin, inputs);
	vector<string> map;
	if (inputs == ":quit") return false;
	else if (inputs.find(":set ") != string::npos)
	{
		playcnt = 0;
		int spaceCount = 0;
		int width = 0;
		int height = 0;

		inputs.erase(0, 5);

		while (inputs[spaceCount] != ' ') spaceCount++;
		for (int i = 0; i < spaceCount; ++i) width += inputs[i] * (i + 1);
		inputs.erase(0, spaceCount + 1);
		for (int i = 0; i < inputs.size(); ++i) height += inputs[i] * (i + 1);

		//Map[row][column]
		for (int i = 0; i < (int)(height-'0'); i++) {
			string tmp;
			getline(cin, tmp);
			map.push_back(tmp);
		}

		_mineSweeper->setMap(width, height, map);
	}
	else if (inputs.find(":toggle ") != string::npos)
	{
		int spaceCount = 0;
		size_t row = 0;
		size_t column = 0;

		inputs.erase(0, 8);

		while (inputs[spaceCount] != ' ') spaceCount++;
		for (int i = 0; i < spaceCount; ++i) row += inputs[i] * (i + 1);
		inputs.erase(0, spaceCount + 1);
		for (int i = 0; i < inputs.size(); ++i) column += inputs[i] * (i + 1);

		_mineSweeper->toggleMine(row, column);
	}
	else if (inputs.find(":play") != string::npos) {
		_mineSweeper->setPlay();
		playcnt++;
	}
	else if (inputs.find(":touch ") != string::npos && playcnt)
	{
		int spaceCount = 0;
		size_t row = 0;
		size_t column = 0;

		inputs.erase(0, 7);

		while (inputs[spaceCount] != ' ') spaceCount++;
		for (int i = 0; i < spaceCount; ++i) row += inputs[i] * (i + 1);
		inputs.erase(0, spaceCount + 1);
		for (int i = 0; i < inputs.size(); ++i) column += inputs[i] * (i + 1);

		_mineSweeper->touchMap(row, column);
	}


	return true;
}

int main()
{

	Minesweeper *minesweeper = new Minesweeper();

	while (mineOperation(minesweeper)) {}

	delete minesweeper;
	return 0;
}

