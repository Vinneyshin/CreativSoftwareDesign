#include <iostream>
#include <stdlib.h>
#include <string>
#include <typeinfo>

using namespace std;

int main() {
	while ( true )
	{
		string inputs;
		int sum = 0;
		int Acount = 0;
		int spaceCount = 0;
		getline(cin, inputs);

		if ( !isdigit(inputs[0]) ) return 0;

		for (int i = 0; i < inputs.size(); ++i)
		{
			if (inputs[i] == ' ') spaceCount++;
		}

		if (spaceCount < 10 && (spaceCount == inputs.substr(0,1)) inputs.erase(0, 2);
		if (spaceCount >= 10) inputs.erase(0, 3);

		for ( int i = 0; i < inputs.size(); ++i )
		{
			int c = inputs[i];
			if ( isdigit(c) && c != 1 ) sum = sum + ( (char)c - '0' );
			else if ( c == 'J' || c == 'Q' || c == 'K' || c == '1' ) sum = sum + 10;
			else if ( c == 'A' )
			{
				Acount++;
			}
		}

		for ( int i = 0; i < Acount; ++i )
		{
			if ( sum > 10 ) sum = sum + 1;
			else sum = sum + 11;
		}

		if ( sum == 21 ) cout << "BlackJack" << endl;
		else if ( sum > 21 ) cout << "Exceed" << endl;
		else cout << sum << endl;
	}
	return 0;
}
