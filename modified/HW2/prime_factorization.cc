#include <iostream>
#include <stdlib.h>


using namespace std;


int main(int argc, char const *argv[])
{
    
    int nData = atoi(argv[1]);

    if(nData < 2 || 65535 < nData) return -1;
    
    int divisor = 2;
    
    //시간복잡도 최악의 경우 n - 2번
    //ex 257은 소수다 만약 257을 입력값으로 주면 divisor가 2부터 257까지 반복해서 올라감
    //빅오 n이니 나쁘지는 않은 알고리즘
    //이를 에라토스테네스의 채로 다시 구현한다면 시간복잡도를 축소시킬 수 있을까?
    //더 비효율적임 차라리 이런 간단한 코드가 나을듯..
    
    while (nData != 1)
    {
        if (nData % divisor == 0) {
            cout << divisor << " ";
            nData /= divisor;
        }
        else {
            divisor++;
        }

        //집중 안했을 때 작성한 바보같은 코드
       
        /*
        while (nData % divisor == 0)
        {
            nData /= divisor;
            cout << divisor;
            cout << endl;
        }
        divisor++;
        */

    }

    cout << endl;

    return 0;
}
