#include <iostream>
#include <string>
#include <algorithm>
#include "reply_admin.h"
using namespace std;

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
	chats.push_back(_chat);
	if (chats.back() == _chat)
		return true;
	else
		return false;
}

bool ReplyAdmin::removeChat(int _index)
{
	if (_index < 0 || _index > chats.size() - 1)
		return false;
	else
	{
		list<string>::iterator it = chats.begin();
		advance(it, _index);
		chats.erase(it);

		// Linked List는 중간에 어떤 값을 찾기 위해선 매번 선형탐색해야함.
		// 그것이 Linked List의 단점 == 특정원소에 접근하기 위해선 선형 탐색 해야함
		/*
		= Vector =
		장점
		1. 개별 원소들 접근 가능
		2. 원소를 마지막에 삽입 하는 것이 빠름
		3. 랜덤으로 원소 순회가 가능
		4. 개별 원소에 대한 접근 속도가 빠름
		단점
		1. 컨테이너 끝이 아닌 곳에 삽입/제거시 성능이 현전히 떨어짐
   		2. 동적이라 확장/축소가 편하나 확장시 비용이 크다.
		   - 메모리를 미리 잡아두고 최대 용량 초과시 그때 새로운 메모리 전체할당
		   - 이럴때 reserve를 현명하게 쓰는것이 좋겠지?
		   - size 함수는 용량 내에서는 메모리를 할당하지 않고 그냥 사이즈만 줄임
		   - 최대치 넘을 경우 새로 할당
		   - reserve는 용량 내던 용량 밖이던 메모리 할당 새로함

		= List =
		장점
		1. 컨테이너 어느 위치에서라도 삽입/제거가 빠름 //그냥 포인터 연결만 하면 되기 때문
   		2. 원소들의 컨테이너 내 이동이 빠름
		단점
		1. 원소의 인덱스로 직접 접근이 불가능함
   		2. 특정 원소에 접근하려면 처음이나 끝부터 선형 탐색을 해야함
   		3. 컨테이너 내 순회가 forward / reverse만 가능하여 느림
   		4. 원소간 상호 연결 정보를 위해 추가적 메모리 비용 발생

		출처: https://loadofprogrammer.tistory.com/76 [큰 꿈을 그리는 프로그래머의 공간.]
		*/
		return true;
	}
}

bool ReplyAdmin::removeChat(list<int> _indices)
{
	bool isRemoved = false;
	while (!_indices.empty())
	{
		if(removeChat(_indices.back()))
		{
			isRemoved = true;
		}
		_indices.pop_back();
	}
	return isRemoved;
}

bool ReplyAdmin::removeChat(int _start, int _end)
{
	bool isRemoved = false;

	for (int i = _start; i <= _end; ++i)
	{
		if(removeChat(_start))
		{
			isRemoved = true;
		}
	}
	return isRemoved;
}

void ReplyAdmin::printChat()
{
	int cnt = 0;
	for (list<string>::iterator it = chats.begin(); it != chats.end(); ++it, ++cnt)
	{
		cout << cnt << " " << *it << endl;
	}
}
