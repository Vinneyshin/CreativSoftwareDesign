#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

/* Implement this function. */

string RadixNotation(unsigned int number, unsigned int radix) {
        
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
