#include "reply_admin.h"

//constructor
ReplyAdmin::ReplyAdmin()
{
    chats = new string[NUM_OF_CHAT];
    addChat("Hello, Reply Administrator!");
    addChat("I will be a good programmer.");
    addChat("This class is awesome.");
    addChat("Professor Lim is wise.");
    addChat("Two TAs are kind and helpful.");
    addChat("I think male TA looks cool.");
}

//destructor
ReplyAdmin::~ReplyAdmin()
{
    delete chats;
}

int ReplyAdmin::getChatCount() const
{
    int i;
    for (i = 0; i < NUM_OF_CHAT; ++i)
    {
        string s = chats[i];
        if (s.empty() == true)
            break;
    }
    return i;
}

bool ReplyAdmin::addChat(string _chat)
{
    if (NUM_OF_CHAT <= getChatCount())
    {
        cout << "ERROR: No more _chat space" << endl;
        return false;
    }
    else
    {
        chats[getChatCount()] = _chat;
        return true;
    }
}

bool ReplyAdmin::removeChat(int _index)
{
    if (getChatCount() - 1 < _index)
    {
        return false;
    }
    else
    {
        int i;
        for (i = _index; i < getChatCount() - 1; i++)
        {
            chats[i] = chats[i + 1];
        }
        chats[i] = "";
        return true;
    }
}

bool ReplyAdmin::removeChat(int *_indices, int _count)
{
    bool result = false;
    bool isTrue = false;
    sort(_indices, _indices + _count);
    for (int i = 0; i < _count; ++i)
    {
        result = removeChat(_indices[i] - i);
        if(result)
            isTrue = true;
    }
    return isTrue;
}

bool ReplyAdmin::removeChat(int _start, int _end)
{
    bool result = false;
    bool isTrue = false;
    if(getChatCount() - 1 < _end)
    {
        int cnt = getChatCount() - 1 - _start + 1;
        for (int i = 0; i < cnt; ++i)
        {
            result = removeChat(_start);
            if (result)
                isTrue = true;
        }
    }
    else
    {
        int cnt = _end - _start + 1;
        for (int i = 0; i < cnt; ++i)
        {
            result = removeChat(_start);
            if(result)
                isTrue = true;
        }
    }
    return isTrue;
}

void ReplyAdmin::printChat()
{
    int count = getChatCount();
    for (int i = 0; i < count; ++i)
    {
        cout << i << " " << chats[i] << endl;
    }
}