#include <iostream>
#include <array>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

enum Strategy 
{
    NOT_CHANGE = 1,
    CHANGE = 2,
    RANDOM = 3,
};

int main(int argc, char const *argv[])
{
    int strategy;
    int repeatCnt = 0;
    int succeedCnt = 0;

    cin >> strategy;
    if(strategy < 1 || strategy > 3) return -1;
    cin >> repeatCnt;

    array<int, 3> door = {0, 0, 1};
    unsigned seed;

    for (int i = 0; i < repeatCnt; i++)
    {
        //time based seed
        seed = chrono::system_clock::now().time_since_epoch().count();
        srand(seed);
        shuffle(door.begin(), door.end(), default_random_engine(seed));
        //we chose the prize
        if(door[0] == 1) {
            if(strategy == NOT_CHANGE) succeedCnt++;
            else if(strategy == RANDOM) {
                int random = rand() % 2;
                //Not Change 
                if(random) succeedCnt++;
            }
        }
        //we couldn't choose the prize
        else {
            if(strategy == CHANGE) succeedCnt++;
            else if(strategy == RANDOM) {
                int random = rand() % 2;
                //Not change
                if(random) succeedCnt++;
            }
        }
    }

    double numerator = static_cast<double> (succeedCnt);
    double denominator = static_cast<double> (repeatCnt);
    printf("%0.1f %% (%d/%d)\n", (numerator/denominator) * 100, succeedCnt, repeatCnt);

    return 0;
}
