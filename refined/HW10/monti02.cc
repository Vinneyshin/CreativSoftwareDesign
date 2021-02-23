#include <iostream>
#include <array>
#include <chrono>
#include <random>
#include <algorithm>
#include <vector>

using namespace std;

enum Strategy 
{
    NOT_CHANGE = 1,
    CHANGE = 2,
    RANDOM = 3,
};

int main(int argc, char const *argv[])
{
    int strategy = 0;
    int repeatCnt = 0;
    int succeedCnt = 0;
    int doorCnt = 0;
    unsigned seed;

    vector<int> door;

    cin >> strategy;
    if(strategy < 1 || strategy > 3) return -1;
    
    cin >> repeatCnt;
    
    cin >> doorCnt;
    if(doorCnt < 2 || doorCnt > 100) return -1;
    
    //reserve the space with initializing with 0.
    door.resize(doorCnt, 0);
    //the prize
    door[0] = 1;

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
            if(strategy == CHANGE) {
                if(door[1] == 1) succeedCnt++;
            }
            else if(strategy == RANDOM) {
                int random = rand() % 2;
                //change
                if(random) {
                    if(door[1] == 1) succeedCnt++;
                }
            }
        }
    }

    double numerator = static_cast<double> (succeedCnt);
    double denominator = static_cast<double> (repeatCnt);
    printf("%0.1f %% (%d/%d)\n", (numerator/denominator) * 100, succeedCnt, repeatCnt);

    return 0;
}
