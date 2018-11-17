#include <iostream>
#include <string>
#include <algorithm>
#include "reply_admin.h"
using namespace std;

int ReplyAdmin::getChatCount()
{
	int i;
	for (i = 0; i < NUM_OF_CHAT; ++i) {
		string s = chats[i];
		if (s.empty() == true) break;
	}
	return i;
}

ReplyAdmin::ReplyAdmin()
{
	this->chats = new string[NUM_OF_CHAT];
}

ReplyAdmin::~ReplyAdmin()
{
	delete[] chats;
}

bool ReplyAdmin::addChat(string _chat)
{
	int num = getChatCount();
	chats[num] = _chat;
	if (chats[num] == _chat) return true;
	else return false;
}

bool ReplyAdmin::removeChat(int _index)
{
	int num = getChatCount();
	if (_index > num-1 || _index < 0) return false;
	else
	{
		for (int i = _index; i < num; i++) {
			chats[i] = chats[i + 1];
		}
		chats[num] = "/0";
		return true;
	}
}

bool ReplyAdmin::removeChat(int * _indices, int _count)
{
	int intcount = 0;
	int num = getChatCount();
	bool booltmp = false;

	sort(_indices,_indices + _count);

	for (int i = 0; i < _count; i++)
	{
		if (_indices[i] <= num && _indices[i] >= 0){
			chats[_indices[i]] = "\0";
			booltmp = true;
		}
	}

	for (int i = 0; i < _count; i++)
	{
		if (_indices[i] <= num && _indices[i] >= 0){				
			for(int j = _indices[i]-intcount; j < num - intcount; j++){
				chats[j] = chats[j + 1];
			}
			intcount++;
		}
	}


	return booltmp;
}

bool ReplyAdmin::removeChat(int _start, int _end)
{
	int num = getChatCount();
	int intcheck = 0;
	if (_start < 0) _start = 0;
	if (_end > num - 1) _end = num - 1;
	bool booltmp = false;

	for (int i = _start; i <= _end; i++)
	{
		chats[i] = "\0";
		booltmp = true;
	}

	if(_end == num - 1) return booltmp;
	else{
		for(int i = 0; i < num-_end+1; i++){
			chats[_start + i] = chats[_end + i + 1];
		}
		return booltmp;
	}
}

void ReplyAdmin::printChat()
{
	int count = getChatCount();
	for (int i = 0; i < count; ++i) {
		cout << i << " " << chats[i] << endl;
	}
}



