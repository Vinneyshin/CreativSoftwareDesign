#include <iostream>
#include <string>
#include <algorithm>
#include "reply_admin.h"

using namespace std;

//getChatCount()
/*
int ReplyAdmin::getChatCount()
{
	int i;
	for ( i = 0; i < NUM_OF_CHAT; ++i )	
	{
		string s = chats[i];
		if ( s.empty() == true ) break;
	}
	return i;
}
*/

ReplyAdmin::ReplyAdmin()
{
	addChat("Hello, Reply Administrator!");
	addChat("I will be a good programmer.");
	addChat("This class is awesome.");
	addChat("Professor Lim is wise.");
	addChat("Two TAs are kind and helpful.");
	addChat("I think male TA looks cool.");
}
ReplyAdmin::~ReplyAdmin()
{
}
bool ReplyAdmin::addChat(string _chat)
{
	int num = chats.size();
	chats.push_back(_chat);
	if ( chats.back() == _chat ) return true;
	else return false;
}
bool ReplyAdmin::removeChat(int _index)
{
	list<string>::iterator it = chats.begin();
	int num = chats.size();
	for ( int i = 0; i < _index; ++i ) it++;
	if ( _index > num - 1 || _index < 0 ) return false;
	else
	{
		chats.erase(it);
		return true;
	}

}
bool ReplyAdmin::removeChat(int * _indices, int _count)
{
	int intcount = 0;
	int num = chats.size();
	bool booltmp = false;
	sort(_indices, _indices + _count);
	for ( int i = 0; i < _count; i++ )
	{
		if ( _indices[i] <= num && _indices[i] >= 0 )
		{
			removeChat(_indices[i] - intcount);
			booltmp = true;
			intcount++;
		}
	}
	/*
	for ( int i = 0; i < _count; i++ )
	{
		if ( _indices[i] <= num && _indices[i] >= 0 )
		{
			for ( int j = _indices[i] - intcount; j < num - intcount; j++ )
			{
				chats[j] = chats[j + 1];
			}
			intcount++;
		}
	}
	*/
	return booltmp;
}
bool ReplyAdmin::removeChat(int _start, int _end)
{
	int num = chats.size();
	int intcount = 0;
	if ( _start < 0 ) _start = 0;
	if ( _end > num - 1 ) _end = num - 1;
	bool booltmp = false;
	for ( int i = _start; i <= _end; i++ )
	{
		removeChat(i - intcount);
		booltmp = true;
		intcount++;
	}
	if ( _end == num - 1 ) return booltmp;
	/*
	else
	{
		for ( int i = 0; i < num - _end + 1; i++ )
		{
			chats[_start + i] = chats[_end + i + 1];
		}
		return booltmp;
	}
	*/
}

void ReplyAdmin::printChat()
{
	int i = 0;
	int count = chats.size();
	for ( list<string>::iterator it = chats.begin(); 
		 it != chats.end(); it++ )
	{
		cout << i << " " << *it << endl;
		++i;
	}
}
