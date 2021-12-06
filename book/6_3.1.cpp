#include <iostream>
using namespace std;

int big(int a, int b)
{
    if(a < 100 && b < 100)
    {
        if(a > b)   return a;
        else        return b;
    }
    else
    {
        return 100;
    }
}

int big(int a, int b, int max)
{
    if(a > max || b > max)
    {
        return max;
    }
    else return big(a, b);
}

int main()
{
    int x = big(3, 5);
    int y = big(300, 60);
    int z = big(30, 60, 50);
    cout << x << ' ' << y << ' ' << z << endl;
}