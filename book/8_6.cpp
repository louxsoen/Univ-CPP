#include <iostream>
#include <string>
using namespace std;

class BaseArray {
private:
    int capacity;
    int *mem;
protected:
    BaseArray(int capacity = 100)
    {
        this->capacity = capacity; mem = new int [capacity];
    }
    ~BaseArray() { delete [] mem; }
    void push(int index, int val) { mem[index] = val; }
    int pop(int index) { return mem[index]; }
    int getCapacity() { return capacity; }
};

class MyStack : public BaseArray {
    int first, last;
public:
    MyStack(int capacity) : BaseArray(capacity) {first = 0; last = 0;}
    void enqueue(int n)
    {
        push(last, n);
        last++;
    }
    int dequeue()
    {
        last--;
        return pop(last);
    }
    int capacity() { return getCapacity(); }
    int length() { return last; }
};

int main()
{
    MyStack mQ(100);
    int n;
    cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
    for(int i = 0 ; i < 5 ; i++)
    {
        cin >> n;
        mQ.enqueue(n);
    }
    cout << "스택 용량:" << mQ.capacity() << ", 스택 크기:" << mQ.length() << endl;
    cout << "스택의 모든 원소를 팝하여 출력한다>> ";
    while(mQ.length() != 0)
    {
        cout << mQ.dequeue() << ' ';
    }
    cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;
}