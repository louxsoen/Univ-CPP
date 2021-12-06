#include <iostream>
#include <string>
using namespace std;
class MyVector {
    int *mem;
    int size;
public:
    MyVector(int n = 100, int val = 100)
    {
        mem = new int[n];
        size = n;
        for(int i = 0 ; i < size ; i++) mem[i] = val;
    }
    ~MyVector() { delete [] mem; }
    void show() 
    { 
        for(int i = size ; i < size ; i++) 
        cout << "엥";
    }
};

int main()
{
    MyVector a(30, 50);
    a.show();
}