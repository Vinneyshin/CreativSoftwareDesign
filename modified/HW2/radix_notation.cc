#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

/* Implement this function. */

string RadixNotation(unsigned int number, unsigned int radix) {
        unsigned int diviend = number, divisor = radix;
        string temp = "";
        
        char radixTable[36];

        for (size_t i = 0; i < 10; i++)
        {
            radixTable[i] = '0' + i;
        }

        for (size_t i = 10; i < 36; i++)
        {
            radixTable[i] = 'a' + (i - 10);
        }
        
        while (diviend != 0)
        {
            temp = radixTable[diviend % divisor] + temp;
            diviend = diviend / divisor;
        }
        
        // quotient + remainder;
        return temp; 
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return -1;

    unsigned int radix;
    
    sscanf(argv[1], "%u", &radix);
    
    if (radix < 2 || radix > 36)
        return -1;
    
    for (int i = 2; i < argc; ++i)
    {
        unsigned int number;
        sscanf(argv[i], "%u", &number);
        cout << RadixNotation(number, radix) << endl;
    }
    
    return 0;
}
