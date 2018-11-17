#include <iostream>
#include <stdlib.h>

using namespace std;

class Base {
	public:
			void showBase() {
						cout << "Base Function" << endl;
							}
};

class Derived :public Base {
	public:
			void showDerived() {
						cout << "Derived Function" << endl;
							}
};

int main() {
		Derived d2;
			Derived *d1 = &d2;

				Base * b = d1; //upcasting
					
					
					//d1 = (Derived*)b; //downcasting


					d1->showBase();
						d1->showDerived();
							system("pause");
}
