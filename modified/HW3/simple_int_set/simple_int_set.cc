#include "simple_int_set.h"

void swap(int* left, int* right);
int partition(int* array, int low, int high);
void quickSort(int* array, int low, int high);

SimpleIntSet::SimpleIntSet(int *_elements, int _count)
{
    mElements = new int[_count];
    for (size_t i = 0; i < _count; i++)
        mElements[i] = _elements[i];
    mElementCount = _count;
    sortElements();
}

SimpleIntSet::~SimpleIntSet()
{
    delete[] mElements;
}

void SimpleIntSet::sortElements()
{
    quickSort(mElements, 0, mElementCount - 1);
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
    // More space than adding two elements() sizes.
    int * tmpElements = new int[mElementCount + _operand.elementCount()];
    int tmpElementsCount = mElementCount;

    for (size_t i = 0; i < mElementCount; i++)
    {
        tmpElements[i] = mElements[i];
    }
    
    for (size_t i = 0; i < _operand.elementCount(); i++)
    {
        bool isRepeated = false;
        int target = _operand.elements()[i];
        
        for (size_t j = 0; j < mElementCount; j++)
        {
            if(mElements[j] == target)
            {
                isRepeated = true;
                break;
            }
        }

        if (!isRepeated)
        {
            tmpElements[tmpElementsCount] = target;
            ++tmpElementsCount;
        }
    }

    delete[] mElements;

    mElements = new int [tmpElementsCount];
    mElementCount = tmpElementsCount;

    for (size_t i = 0; i < mElementCount; i++)
    {
        mElements[i] = tmpElements[i];
    }

    return this;
}

SimpleIntSet* SimpleIntSet::differenceSet(SimpleIntSet& _operand)
{   
    for (size_t i = 0; i < _operand.elementCount(); i++)
    {
        int target = _operand.elements()[i];
        for (size_t j = 0; j < mElementCount; j++)
        {
            if(mElements[j] == target)
            {
                int repeatedIndex = j;
                int last_index = mElementCount - 1;

                // Move one index to the left            
                if(!(repeatedIndex == last_index))
                {
                    for (size_t k = repeatedIndex; k < last_index; k++)
                    {
                        mElements[k] = mElements[k + 1];
                    }
                }
                --mElementCount;
                break;
            }
        }
    }

    int * tmpElements = new int[mElementCount];
    int tmpElementsCount = mElementCount;
    
    for (size_t i = 0; i < tmpElementsCount; i++)
    {
        tmpElements[i] = mElements[i];
    }

    delete[] mElements;
    mElements = tmpElements;

    return this;
}

SimpleIntSet* SimpleIntSet::intersectSet(SimpleIntSet& _operand)
{
    int max = mElementCount > _operand.elementCount() ? mElementCount : _operand.elementCount();
    int * tmpElements = new int [max];
    int repeatCnt = 0;

    for (size_t i = 0; i < _operand.elementCount(); i++)
    {
        int target = _operand.elements()[i];
        for (size_t j = 0; j < mElementCount; j++)
        {
            if(mElements[j] == target)
            {
                tmpElements[repeatCnt] = target;
                ++repeatCnt;
                break;
            }
        }
    }

    delete[] mElements;
    mElements = new int [repeatCnt];
    mElementCount = repeatCnt;
    
    for (size_t i = 0; i < mElementCount; i++)
    {
        mElements[i] = tmpElements[i];
    }
    return this;
}

void swap(int* left, int* right){
    int tmp = *left;
    *left = *right;
    *right = tmp;
}

int partition(int* array, int low, int high) {
    // Set the rightmost as a pivot
    int pivot = array[high];
    int i = (low - 1);

    for (size_t j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return i + 1;
    
}

void quickSort(int* array, int low, int high) {
    //"high" variable is rightmost
    //"low" variable is leftmost
    if(low < high)
    {
        int pi = partition(array, low, high); 
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}
