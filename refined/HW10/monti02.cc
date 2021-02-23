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
            int randomDoor = rand() % (doorCnt - 2);
            if(strategy == CHANGE) {
                //우리가 만약 상을 고르면.. (randomDoor가 0인경우)
                //현재 randomDoor은 사회자가 연 문과 내가 선택한 문 뺀 나머지(doorCnt - 2)
                //그중 딱 하나만 정답임 그게 0인 경우고. (경우의수로 계산중)
                if(!randomDoor) succeedCnt++;
            }
            else if(strategy == RANDOM) {
                // 1/2의 확률을 곱해주는중..
                int random = rand() % 2;
                if(random) {
                    if(!randomDoor) succeedCnt++;
                }
            }
        }
    }

    double numerator = static_cast<double> (succeedCnt);
    double denominator = static_cast<double> (repeatCnt);
    printf("%0.1f %% (%d/%d)\n", (numerator/denominator) * 100, succeedCnt, repeatCnt);

    return 0;
}
