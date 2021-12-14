#include <iostream>
#include <string>
using namespace std;

class AbstractStack {
public:
    virtual bool push(int n) = 0; // 스택에 n 푸시, 스택이 full이면 false 리턴
    virtual bool pop(int& n) = 0; // 스택에 팝한 정수 n을 저장하고 스택이 empty면 false 리턴
    virtual int size() = 0; // 현재 스택에 저장된 정수의 개수
};

class IntStack : public AbstractStack {
    int *p;
    int max, usage;
public:
    IntStack(int n)
    {
        p = new int[n];
        max = n;
        usage = 0;
    }
    bool push(int n)
    {
        if(usage == max) return false;
        p[usage] = n;
        usage++;
        return true;
    }
    bool pop(int& n)
    {
        if(usage < 0) return false;
        n = p[usage];
        usage--;
        return true;
    }
    ~IntStack() { delete [] p; }
    int size() { return usage; }
};

int main()
{
    IntStack a(10);
    int r;

    a.push(10);
    a.push(20);
    a.push(30);
    a.push(40);
    a.push(50);
    a.push(60);
    
    cout << "현재 스택의 원소 개수 : " << a.size() << endl;
    for(int i = 0 ; i < 5 ; i++)
    {
        a.pop(r);
        cout << r << endl;
    }
    cout << "현재 스택의 원소 개수 : " << a.size() << endl;
}