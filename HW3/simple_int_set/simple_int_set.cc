#include "simple_int_set.h"
#include <string>
#include <iostream>
using namespace std;

void SimpleIntSet::sortElements() {
	int check = 0;
	for (int i = 0; i< mElementCount - 1; i++) {
		while (mElements[i] > mElements[i + 1]) {
				int temp = mElements[i];
				mElements[i] = mElements[i+1];
				mElements[i+1] = temp;
		}
	}
}
SimpleIntSet::SimpleIntSet(int *_elements, int _count) {
	mElementCount = _count;
	mElements = new int[mElementCount];
	for(int i =0; i < mElementCount; i++) {
        	mElements[i] = _elements[i];
	}
	sortElements();
}
SimpleIntSet::~SimpleIntSet() { 
	delete[] mElements;
}
int* SimpleIntSet::elements() const{
	return mElements;
}
int SimpleIntSet::elementCount() const {
	return mElementCount;
}
SimpleIntSet* SimpleIntSet::unionSet(SimpleIntSet& _operand) {
    	int* array = new int[_operand.elementCount() + mElementCount];
        int arraycheck;
        int count = 0;
        for(int i = 0; i < mElementCount; i++) {
                array[i] = mElements[i];
        }
        for(int i = 0; i < _operand.elementCount(); i++) {
                int input = _operand.elements()[i];
                int number = 0;
                while ( 1 ) {
                        if(input == mElements[number])  {
                                break;
                        }
                        if (number == elementCount()) {
                                array[elementCount()+count] = input;
                                count += 1;
                                break;
                        }
			number +=1;
		}
	}
	arraycheck = mElementCount + count;
    	mElements = array;
    	mElementCount = arraycheck;
    	sortElements();

    	return new SimpleIntSet(array, arraycheck);
}
SimpleIntSet* SimpleIntSet::differenceSet(SimpleIntSet& _operand) {
    	int* array = new int[mElementCount];
    	int arraycheck;
    	int count = 0;
    	for(int i = 0; i < mElementCount; i++) {
        	int input = mElements[i];
        	int number = 0;
		while ( 1 ) {
                        if(input == _operand.mElements[number])  {
                                break;
                        }
                        if (number == _operand.elementCount()) {
                                array[count] = input;
                                count += 1;
                                break;
                        }
			number+=1;
                }
    	}
    	arraycheck = count;
    	mElements = array;
    	mElementCount = arraycheck;
    	sortElements();
    	return new SimpleIntSet(array, arraycheck);
}
SimpleIntSet* SimpleIntSet::intersectSet(SimpleIntSet& _operand) {
    	int* array = new int[mElementCount];
    	int arraycheck;
    	int count = 0;
    	for(int i = 0; i < mElementCount; i++) {
        	int input = mElements[i];
        	int number = 0;
                while ( 1 ) {
                        if(input == _operand.mElements[number])  {
				array[count] = input;
				count +=1;
                                break;
                        }
                        number +=1;
                        if (number == _operand.elementCount()) {
                                break;
                        }
                }
   	}
    	arraycheck = count;
    	mElements = array;
    	mElementCount = arraycheck;
    	sortElements();
    	return new SimpleIntSet(array, arraycheck);
}
void SimpleIntSet::printSet() {
    	string string = "{ ";
   	for(int i = 0; i < mElementCount; i++) {
        	string += to_string(mElements[i]) + " ";
    	}
    	string += "}";
    	cout<<string<<endl;
}
