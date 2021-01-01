#include "simple_int_set.h"

SimpleIntSet::SimpleIntSet(int *_elements, int _count)
{
    mElements = new int[_count];
    for (size_t i = 0; i < _count; i++)
        mElements[i] = _elements[i];
    mElementCount = _count;
}

SimpleIntSet::~SimpleIntSet()
{
    delete mElements;
}

void SimpleIntSet::sortElements()
{
    sort(mElements, mElements + mElementCount);
}

void SimpleIntSet::printSet()
{
    cout << "{ ";
    for (size_t i = 0; i < mElementCount; i++)
    {
        cout << mElements[i] << " "; 
    }
    cout << "}" << endl;
}

SimpleIntSet* SimpleIntSet::unionSet(SimpleIntSet& _operand)
{
    for (size_t i = 0; i < _operand.elementCount(); i++)
    {
        bool isRepeated = false;
        for (size_t j = 0; j < mElementCount; j++)
        {
            if(mElements[j] == _operand.elements()[i])
            {
                isRepeated = true;
                break;
            }
        }
        if(!isRepeated)
        {
            int * tmpElements = new int[++mElementCount];
            for (size_t j = 0; j < mElementCount - 1; j++)
                tmpElements[j] = mElements[j];
            
            tmpElements[mElementCount - 1] = _operand.elements()[i];
            
            //re-assigning heap memory to avoid memory leak.
            delete mElements;
            mElements = new int[mElementCount];
            
            for (size_t i = 0; i < mElementCount; i++)
                mElements[i] = tmpElements[i];
            delete tmpElements;
        }
    }
    sortElements();
    return this;
}

SimpleIntSet* SimpleIntSet::differenceSet(SimpleIntSet& _operand)
{
    for (size_t i = 0; i < _operand.elementCount(); i++)
    {
        bool isRepeated = false;
        int repeatedIndex = -1;
        for (size_t j = 0; j < mElementCount; j++)
        {
            if(mElements[j] == _operand.elements()[i])
            {
                isRepeated = true;
                repeatedIndex = j;
                break;
            }
        }
        if(isRepeated)
        {
            int last_index = mElementCount - 1;
            
            if(!(repeatedIndex == last_index))
                for (size_t i = repeatedIndex; i < last_index; i++)
                    mElements[i] = mElements[i + 1];
            
            int * tmpElements = new int[--mElementCount];

            for (size_t j = 0; j < mElementCount; j++)
                tmpElements[j] = mElements[j];
            
            
            //re-assigning heap memory to avoid memory leak.
            delete mElements;
            mElements = new int[mElementCount];
            
            for (size_t i = 0; i < mElementCount; i++)
                mElements[i] = tmpElements[i];

            delete tmpElements;
        }
    }
    sortElements();
    return this;
}

SimpleIntSet* SimpleIntSet::intersectSet(SimpleIntSet& _operand)
{
    int * repeatElements = NULL;
    for (size_t i = 0; i < _operand.elementCount(); i++)
    {
        bool isRepeated = false;
        int repeatedIndex = -1;
        int repeatCnt = 0;
        for (size_t j = 0; j < mElementCount; j++)
        {
            if(mElements[j] == _operand.elements()[i])
            {
                isRepeated = true;
                repeatedIndex = j;
                ++repeatCnt;
                int * tmpElements = new int[repeatCnt];
                repeatElements = tmpElements;
                repeatElements[repeatCnt - 1] = _operand.elements()[i];
                break;
            }
        }

        if(isRepeated)
        {
            if(repeatElements = NULL)
            {
                int * tmpElements = new int[repeatCnt];
                repeatElements = tmpElements;
            }
            else 
            {
                
            }

            
            
            
            //re-assigning heap memory to avoid memory leak.
            delete mElements;
            mElements = new int[mElementCount];
            
            for (size_t i = 0; i < mElementCount; i++)
                mElements[i] = tmpElements[i];

            delete tmpElements;
        }
    }
    return this;
}

//TODO 각 함수마다 반복되는 부분 private 함수로 빼서 최적화하기

//