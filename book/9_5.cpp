#include <iostream>
#include <string>
using namespace std;

class AbstractGate {
protected:
    bool x, y;
public:
    AbstractGate() {;}
    void set(bool x, bool y) { this->x = x; this->y = y; }
    virtual bool operation() = 0;
};

class ANDGate : public AbstractGate {
public:
    ANDGate(bool x = false, bool y = false) : AbstractGate() { set(x, y); }
    bool operation()
    {
        if(x == true && y == true) return true;
        else return false;
    }
};

class ORGate : public AbstractGate {
public:
    ORGate(bool x = false, bool y = false) : AbstractGate() { set(x, y); }
    bool operation()
    {
        if(x == true && y == true) return false;
        else return true;
    }
};

class XORGate : public AbstractGate {
public:
    XORGate(bool x = false, bool y = false) : AbstractGate() { set(x, y); }
    bool operation()
    {
        if( (x == false && y == true) || (x == true && y == false) )
        return true; 
        else return false;
    }
};

int main()
{
    ANDGate andGate;
    ORGate orGate;
    XORGate xorGate;

    andGate.set(true, false);
    orGate.set(true, false);
    xorGate.set(true, false);
    cout.setf(ios::boolalpha);
    cout << andGate.operation() << endl;
    cout << orGate.operation() << endl;
    cout << xorGate.operation() << endl;
}