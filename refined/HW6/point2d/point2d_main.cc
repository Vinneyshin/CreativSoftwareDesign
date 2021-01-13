#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <array>
#include "point2d.h"

using namespace std;

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{

	string command;
	map<string, Point> vectors;
	array<string, 3> inputs;

	while (true)
	{
		getline(cin, command);
		
		string token;
		auto it = inputs.begin();

		if (command.find("set") != string::npos)
		{
			command.erase(0, 4);
			stringstream ss(command);

			while (getline(ss, token, ' ') && it != inputs.end())
			{
				*it = token;
				++it;
			}

			string key = inputs.at(0);
			int unit_x = stoi(inputs.at(1)), unit_y = stoi(inputs.at(2));
			Point point(unit_x, unit_y);

			vectors.insert(pair<string, Point>(key, point));
		}

		else if (command.find("eval") != string::npos)
		{
			command.erase(0, 5);
			stringstream ss(command);
		
			while (getline(ss, token, ' ') && it != inputs.end())
			{
				*it = token;
				++it;
			}
			
			Point lhs;
			Point rhs;
			string cal_type = inputs.at(1);
			int index = 0;
			bool isExist = true;

			for (Point* point : {&lhs, &rhs})
			{
				string key;
				bool isMinus = false;

				key = inputs.at(index);
				if(key[0] == '-')
				{
					key.erase(0);
					isMinus = true;
				}
				if(isNumber(key))
				{
					*point = Point(stoi(key));
				}
				else
				{
					if(vectors.find(key) == vectors.end())
					{
						isExist = false;
						break;
					}
					*point = vectors[key];
				}
				if(isMinus)
				{
					*point = -*point;
				}
				index = 2;
			}

			if(!isExist)
			{
				cout << "input error" << endl;
				continue;
			}

			if (cal_type == "+")
			{
				cout << (lhs + rhs) << endl;
			}
			else if (cal_type == "-")
			{
				cout << (lhs - rhs) << endl;
			}
			else if (cal_type == "*")
			{
				cout << (lhs * rhs) << endl; 
			}
			else
			{
				cout << "Invalid cal_type" << endl;
			}
		}
		else if (command == "quit")
		{
			break;
		}
		else
		{
			cout << "invalid command" << endl;
		}
	}
	return 0;
}
