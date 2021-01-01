#include <iostream>

using namespace std;

class Test {
	int x;
	public:
	virtual void show() = 0;
	int getX() {
		return x;
	}
};

class TestDerived : public Test {
	void show(){
	}
};

int main(){
	TestDerived t;
	return 0;
}

