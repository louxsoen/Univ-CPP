#include <iostream>
#include <string>
using namespace std;

class LoopAdder {
    string name;
    int x, y, sum;
    void read()
    {
        cout << name << ":" << endl;
        cout << "처음 수에서 두번재 수까지 더합니다. 두 수를 입력하세요 >> ";
        cin >> x >> y;
    }
    void write()
    {
        cout << x << "에서 " << y << "까지의 합 = " << sum << " 입니다" << endl;
    }
protected:
    LoopAdder(string name = "") { this->name = name; } // 루프의 이름을 받음 
    int getX() { return x; }
    int getY() { return y; }
    virtual int calculate() = 0; // 순수 가상 함수. 루프를 돌며 합을 구하는 함수
public:
    void run()
    {
        read();
        sum = calculate();
        write();
    }
};

class WhileLoopAdder : public LoopAdder {
    string name;
public:
    WhileLoopAdder(string name) : LoopAdder(name) { this->name = name; }
    int calculate()
    {
        int sum = 0;
        int x = getX(), y = getY();
        while(x != y + 1)
        {
            sum += x;
            x++;
        }
        return sum;
    }
};

class DoWhileLoopAdder : public LoopAdder {
    string name;
public:
    DoWhileLoopAdder(string name) : LoopAdder(name) { this->name = name; }
    int calculate()
    {
        int sum = 0;
        int x = getX(), y = getY();
        do
        {
            sum += x;
            x++;
        } while (x != y + 1);
        
        return sum;
    }
};

int main()
{
    WhileLoopAdder whileloop("While Loop");
    DoWhileLoopAdder dowhileloop("Do While Loop");

    whileloop.run();
    dowhileloop.run();
}