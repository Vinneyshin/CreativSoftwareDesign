#include <iostream>
#include <regex>

using namespace std;

struct Term
{
    int degree;
    int coefficient;
};

class Polynomial
{
private:
    vector<Term> terms;
public:
    Polynomial(const string& expr);
    void differentiate();
    int calculate(int nData);
};

Polynomial::Polynomial(const string& expr)
{
    regex reg(R"((-?)((\d*)[x-zA-Z](\^(\d+))?|(\d+)))");
    string str = expr;
    smatch m;

    while (regex_search(str, m, reg))
    {   
        vector<string> arr;

        for(auto& sm : m) {
            arr.push_back(sm);
        }
        
        bool isNegative = arr[1][0] == '-';

        // if we input -3x^2 it arr would be
        // {-3x^2, -, 3x^2, 3, ^2, 2, ""}
        // if we do same on 11
        // {11, "", 11, "", "", "", 11}
        // Therefore We check arr[6] which contain ""
        Term term;

        if(!arr[6].empty()) {
            //zero degree
            term.degree = 0;
            term.coefficient = stoi(arr[6]);    
        }
        else {
            //more than zero degree
            term.degree = arr[5].empty() ? 1 : stoi(arr[5]);
            term.coefficient = arr[3].empty() ? 1 : stoi(arr[3]);
        }

        if(isNegative) {
            term.coefficient *= -1;
        }

        terms.push_back(term);
        str = m.suffix();
    }
}

void Polynomial::differentiate() {
    for(Term& term : terms) {
        if (term.degree)
        {
            term.coefficient *= term.degree;
            --term.degree; 
        }
        else
        {
            term.coefficient = 0;
        }
    }
}

int Polynomial::calculate(int nData) {
    int sum = 0;
    for(Term& term : terms) {
        if (term.degree)
        {
            int x = 1;
            for (int i = 0; i < term.degree; i++)
            {
                x *= nData;
            }
            sum += term.coefficient * x;
        }
        else
        {
            sum += term.coefficient;
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    string input;
    int nData;
    while (true)
    {
        cin >> input;
        if(input == "quit")
        {
            break;
        }
        cin >> nData;
        Polynomial poly(input);
        poly.differentiate();
        cout << poly.calculate(nData) << endl;
        cin.clear();
    }
    return 0;
}
