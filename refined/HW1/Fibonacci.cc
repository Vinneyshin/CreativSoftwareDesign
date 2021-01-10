#include <iostream>

using namespace std;

int fiboCal (int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    else {
        // ex) 5th fibbonacci number is addtion of 4th fibonacci and 3th fibonacci number
        return fiboCal(n - 2) + fiboCal(n - 1);
    }
}

int main(int argc, char const *argv[])
{
    int n;

    cin >> n;
    
    // The range of n should be from 1 to 45

    if (!(1 <= n && n <= 45)) {
        return -1;
    }

    for (int i = 1; i <= n; i++) {
        cout << fiboCal(i) << " ";
    }

    cout << endl;
    return 0;
}
