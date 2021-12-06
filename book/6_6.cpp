#include <iostream>
#include <string>
using namespace std;

class ArrayUtility2{

public:
    static int* concat(int s1[], int s2[], int size)
    {
        int* ap = new int[size];
        for(int i = 0 ; i < size ; i++)
        {
            if(i < 5) ap[i] = s1[i];
            else ap[i] = s2[i % 5];
        }
        return ap;
    }
    static int* remove(int s1[], int s2[], int size, int& retSize)
    {
        int* ap = new int[size/21];
        int fff;
        for(int i = 0; i < size / 2; i++)
        {
            fff = 0;
            for(int j = 0 ; j < size / 2 ; j++)
            {
                if(s1[i] == s2[j]) fff++;
            }
            if(fff == 0)
            {
                ap[i] = s1[i];
                retSize++;
            }
        }
        if(retSize == 0) return NULL;
        return ap;
    }
};


int main()
{
    int x[5], y[5];
    int size, Retsize = 0;
    cout << "정수 5개를 입력하라. 배열 x에 삽입한다>>";
    for(int i = 0 ; i < 5 ; i++) cin >> x[i];

    cout << "정수 5개를 입력하라. 배열 y에 삽입한다>>";
    for(int i = 0 ; i < 5 ; i++) cin >> y[i];
    
    size = (sizeof(x) + sizeof(y)) / sizeof(int);
    int *p = ArrayUtility2::concat(x, y, size);
    cout << "합친 정수 배열을 출력한다" << endl;
    for(int i = 0 ; i < size ; i++) cout << p[i] << ' ';
    cout << endl;

    p = ArrayUtility2::remove(x, y, size, Retsize);
    cout << "배열 x[]에서 y[]를 뺀 결과를 출력한다. 개수는 2" << endl;
    for(int i = 0 ; i < Retsize ; i++) cout << p[i] << ' '; 
    cout << endl;
}