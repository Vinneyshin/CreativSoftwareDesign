#include <iostream>
#include <stdlib.h>
#include <string>

#include "simple_int_set.h"

using namespace std;

enum EOperateType
{
    Invalid = -1,
    
    Add,
    Sub,
    Mul,
    Print,
};
typedef enum EOperateType OperateType;

int main(void)
{
    while(true)
    {
        string inputs;
        getline(cin, inputs);
        
        if(inputs == "0") break;
        
        string *argv = new string[inputs.length()]; // more than count
        string token;
        size_t pos;
        int argc = 0;
        
        while(true)
        {
            pos = inputs.find(' ');
            token = inputs.substr(0, pos);
            
            argv[argc++] = token;
            
            if(pos >= inputs.length()) break;
            else inputs.erase(0, pos + 1);
        }
        
        set<int> left;
        set<int> right;
        set <int> elements;
        set <int> result;

        OperateType type = Invalid;
        
        for(int i=0; i < argc; ++i)
        {
            string arg = argv[i];
            if(arg == "{" && elements.size() == 0) elements.clear();
            else if(isdigit(arg[arg.length() - 1]))
            {
                elements.insert(atoi(arg.c_str()));
            }
            else if(arg == "}")
            {
                if(left.empty()) left = elements;
                else if(right.empty()) right = elements;
                
                elements.clear();
                if(type == Invalid) type = Print;
            }
            else if(arg == "+") type = Add;
            else if(arg == "-") type = Sub;
            else if(arg == "*") type = Mul;
        }
        
        switch(type)
        {
            case Add:
                result = SimpleIntSet::SetUnion(left, right); break;
            case Sub:
                result = SimpleIntSet::SetDifference(left, right); break;
            case Mul:
                result = SimpleIntSet::SetIntersection(left, right); break;
            default: break;
        }
        if(type != Invalid) SimpleIntSet::SetPrint(result);
    }
    return 0;
}