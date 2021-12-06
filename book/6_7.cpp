#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Random{

public:
    static void seed() { srand((unsigned)time(0)); }
    static int nextInt(int min = 0, int max = 32767) { return rand() % (max + 1); }
    static char nextAlphabet()
    {
        if(rand() % 2 == 1)
        return rand() % 26 + 'A';
        else return rand() % 26 + 'a';
    }
    static double nextDouble()
    {
        double a = rand();
        return rand() / a;
    }
};

int main()
{
    cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다" << endl;
    for(int i = 0 ; i < 10 ; i++) cout << Random::nextInt(1, 100) << ' ';
    cout << endl;

    cout << "알파벳을 랜덤하게 10개 출력합니다" << endl;
    for(int i = 0 ; i < 10 ; i++) cout << Random::nextAlphabet() << ' ';
    cout << endl;

    cout << "랜덤한 실수 10개를 출력합니다" << endl;
    for(int i = 0 ; i < 10 ; i++) cout << Random::nextDouble() << ' ';
    cout << endl;
}