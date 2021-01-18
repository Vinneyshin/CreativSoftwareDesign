#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

int main(int argc, char const *argv[])
{
    while (true)
    {
        string str, temp;
        vector<string> cards_vec;

        getline(cin, str);

        stringstream ss(str);

        while (getline(ss, temp, ' '))
            cards_vec.push_back(temp);

        //그냥 getline(cin, str, ' ') 했을땐 안됨
        //왜 그랬을까 생각하기
        //아마 cin이라 계속 연속으로 입력될 수 밖에 없어서?
        //ss처럼 끝이 존재해야하는데 cin은 키보드가 죽기
        //전까지는 계속 동작하잖아

        int sum = 0;
        bool is_a_exist = false;
        
        for (vector<string>::const_iterator it = cards_vec.begin();
             it != cards_vec.end(); ++it)
        {
            if (*it == "10" || *it == "J" || *it == "Q" || *it == "K")
                sum += 10;
            else if (*it == "A")
                is_a_exist = true;
            else
                sum += stoi(*it);
        }

        if (is_a_exist)
        {
            if (sum + 11 > 21)
                sum += 1;
            else
                sum += 11;
        }

        if (sum > 21)
            cout << "Exceed" << endl;
        else if (sum == 21)
            cout << "BlackJack" << endl;
        else
            cout << sum << endl;
    }
    return 0;
}
