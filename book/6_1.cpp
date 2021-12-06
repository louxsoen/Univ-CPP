#include <iostream>
using namespace std;

int add(int a[], int num)
{
    int val = 0;
    for(int i = 0 ; i < num ; i++)
    val += a[i];
    return val;
}
int add(int a[], int num, int b[])
{
    int val = 0;
    for(int i = 0 ; i < num ; i++)
    val += a[i] + b[i];
    return val;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {6, 7, 8, 9, 10};
    int c = add(a, 5); // 배열 a의 정수 모두 더한 값 리턴
    int d = add(a, 5, b); // 배열 a와 b의 정수 모두 더한 값 리턴
    cout << c << endl; // 15출력
    cout << d << endl; // 55 출력
}