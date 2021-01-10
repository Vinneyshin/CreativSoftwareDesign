#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vi(10);

    while (true)
    {
        int x;
        cin >> x;
        vi.push_back(x);
    }
    
    return 0;
}
