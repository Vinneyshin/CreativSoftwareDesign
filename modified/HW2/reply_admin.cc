#include <iostream>
#include <string>
#include <stdio.h>
#include <cctype>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

const int NUM_OF_CHAT = 200;

int getChatCount(string *_chatList)
{
    int i;
    for (i = 0; i < NUM_OF_CHAT; ++i)
    {
        string s = _chatList[i];
        if (s.empty() == true)
            break;
    }
    return i;
}

void printChat(string *_chatList)
{
    int count = getChatCount(_chatList);
    for (int i = 0; i < count; ++i)
    {
        cout << i << " " << _chatList[i] << endl;
    }
}

// Implement these functions

// returns true when adding chat is succeeded
bool addChat(string *_chatList, string _chat)
{
    _chatList[getChatCount(_chatList)] = _chat;
    return true;
}

// returns true when removing chat is succeeded
bool removeChat(string *_chatList, int _index)
{
    int i;
    for (i = _index; i < getChatCount(_chatList) - 1; i++)
    {
        _chatList[i] = _chatList[i + 1];
    }
    _chatList[i] = "";
    return true;
}

int findNumber(string command, int *cursor)
{
    string number;

    while (isdigit(command.at(*cursor)))
    {
        number = number + command.at(*cursor);
        (*cursor)++;
        if (command.size() == *cursor)
            break;
    }

    return stoi(number);
}

// Implement commented (/* */) areas in main function
int main(void)
{

    string *chats = new string[NUM_OF_CHAT];

    addChat(chats, "Hello, Reply Administrator!");
    addChat(chats, "I will be a good programmer.");
    addChat(chats, "This class is awesome.");
    addChat(chats, "Professor Lim is wise.");
    addChat(chats, "Two TAs are kind and helpful.");
    addChat(chats, "I think TAs look cool.");

    while (true)
    {
        string command;
        getline(cin, command);
        if (command.at(0) == '#')
        {
            if (command.compare("#quit") == 0)
                break;
            else if (command.compare(0, 8, "#remove ") == 0)
            //from position 0, if 7 indicies are equal to string "#remove", it returns 0
            {
                string removed = command.erase(0, 8);


                int cursor = 0;
                bool result = false;

                int fNum = findNumber(command, &cursor);

                if (command.find('-') != string::npos)
                {
                    cursor++;
                    int sNum = findNumber(command, &cursor);

                    //if user input a number larger than whole chat size.

                    if (getChatCount(chats) - 1 < sNum)
                    {
                        int cnt = getChatCount(chats) - 1 - fNum + 1;
                        while (cnt)
                        {
                            result = removeChat(chats, fNum);
                            cnt--;
                        }
                    }
                    else
                    {
                        int cnt = sNum - fNum + 1;
                        while (cnt)
                        {
                            result = removeChat(chats, fNum);
                            cnt--;
                        }
                    }
                }
                else if (command.find(',') != string::npos)
                {
                    int* indicies = new int[command.size()/2 + 1];
                    
                    stringstream check1(command);
                    string tmp;

                    int i = 0;

                    while (getline(check1, tmp, ','))
                    {
                        indicies[i] = stoi(tmp);
                        i++;
                    }

                    
                    sort(indicies, indicies + i);

                    int cnt = 0;

                    for (int j = 0; j < i; j++)
                    {
                        result = removeChat(chats, indicies[j] - cnt);
                        cnt++;
                    }
                    
                }
                else
                {
                    result = removeChat(chats, fNum);
                }

                if (result)
                {
                    printChat(chats);
                }
            }
        }
        else if (addChat(chats, command))
            printChat(chats);
    }

    // delete chatting list
    delete[] chats;
    return 0;
}