#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
const int NUM_OF_CHAT = 200;
int cnt2=0;
int to_int(string str)
{
	int arr[100];
	int num = 1, index = 0;
	for (int i = 0; i < str.length(); i++)
		arr[i] = str[i] - 48;
	for (int i = 0; i < str.length(); i++)
	{
		index += arr[str.length() - i - 1] * num;
		num *= 10;
	}
	return index;
}
int getChatCount(string *_chatList) {
	int i;
	for (i = 0; i < NUM_OF_CHAT; ++i) {
		string s = _chatList[i];
		if (s.empty() == true) break;
	}
	return i;
}
void printChat(string *_chatList) {
	int count = getChatCount(_chatList);
	for (int i = 0; i<count; ++i) {
		cout << i << " " << _chatList[i] << endl;
	}
}
int cnt = 0;
bool addChat(string*_chatList, string _chat) {
	_chatList[cnt-cnt2] = _chat;
	cnt++;
	return true;
}
bool removeChat(string *_chatList, int _index) {
	int num = getChatCount(_chatList);
	for (int i = _index; i < num; i++) {
		_chatList[i] = _chatList[i + 1];
		_chatList[i + 1] = "\0";
	}
	cnt2++;
	return true;
}
int main(void) {
	string* chats = new string[NUM_OF_CHAT];addChat(chats, "Hello, Reply Administrator!");addChat(chats, "I will be a good programmer.");addChat(chats, "This class is awesome.");addChat(chats, "Professor Lim is wise.");addChat(chats, "Two TAs are kind and helpful.");addChat(chats, "I think TAs look cool.");
	while (true) {
		string command;getline(cin, command);
		if (command == "#quit") break;
		else if (command.substr(0, 8) == "#remove ") {string removed = command.erase(0, 8);int num = getChatCount(chats);
			if (command.find(",") == string::npos && command.find("-") == string::npos) {int idx = to_int(removed);if (idx < getChatCount(chats)) { removeChat(chats, idx); printChat(chats);}
			}
			else if (command.find(",") == string::npos)
			{
				string s_start ="";
				string s_end = ""; 
				int index = 0;
				while (command[index] != '-') {
					index++;
				}
				for (int i = 0; i < index; i++)
					s_start = s_start + command[i];
				for (int i = index+1; i < command.length(); i++)
					s_end = s_end + command[i];
				int start = to_int(s_start), end = to_int(s_end);
				if (start >= 0 && end < getChatCount(chats)) {
					for (int i = start; i <= end; i++)
						removeChat(chats, start);
					printChat(chats);
				}
			}
			else if (command.find("-") == string::npos)
			{
				int cnt = 0;
				int num = getChatCount(chats);
				while (command.find(",") != string::npos) {
					int temp = 0;
					string str;
					while (command[temp] != ',') {
						temp++;
					}
					for (int i = 0; i < temp; i++)
						str = str + command[i];
					removeChat(chats,to_int(str)-cnt);
					command.erase(0, temp+1);
					cnt++;
				}
				int last_int = to_int(command);
				removeChat(chats, last_int-cnt);
				if (cnt < num) printChat(chats);
			}
		}
		else if(addChat(chats, command)) printChat(chats);}delete[] chats;return 0;
}
