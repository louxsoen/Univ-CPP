#include <iostream>
using namespace std;

int big(int a, int b, int max = 100)
{
    if(a < max && b < max)
    {
        if(a > b)   return a;
        else        return b;
    }
    else
    {
        return max;
    }
}

int main()
{
    int x = big(3, 5);
    int y = big(300, 60);
    int z = big(30, 60, 50);
    cout << x << ' ' << y << ' ' << z << endl;
}