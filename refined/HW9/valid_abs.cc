#include <iostream>
#include <vector>

using namespace std;

bool getInputs(int& nData, vector<string>& inputs) {
    try
    {
        string tmp;

        for (int i = 0; i < nData; ++i)
        {
            cin >> tmp;
            inputs.push_back(tmp);
        }
        return true;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

bool checkVABS(vector<string>& inputs) {
    try
    {
        string line;
        for (vector<string>::iterator it = inputs.begin(); it != inputs.end(); ++it)
        {
            int lhs = 0;
            int rhs = 0;

            line = *it;
            
            if(line.front() == '>')
            {
                cout << "NO" << endl;
                continue;
            }
            
            for (int i = 0; i < line.size(); ++i)
            {
                if(line[i] == '<') ++lhs;
                else if(line[i] == '>') ++rhs;
                else {
                    cout << "NO" << endl;
                    continue;
                } 
                
            }
            cout << (lhs == rhs ? "YES" : "NO") << endl;
        }
        return true;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

int main(int argc, char const *argv[])
{
    int nData = 0;
    //If string inputs come in, nData's value will remain as 0.
    cin >> nData;

    vector<string> inputs;

    getInputs(nData, inputs);
    checkVABS(inputs);

    return 0;
}