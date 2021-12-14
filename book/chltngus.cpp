#include <iostream>
using namespace std;

class parent {
    int a;
public:
    parent(int a = 0)
    {
        this->a = a;
    } 
    void print() const {
        cout << "parent : " << a << endl;
    }
    void testset(int a) const {
        this->a = a;
    }
};


class child : public parent {
    int a;
public:
    child(int a = 0)
    {
        this->a = a;
    }
    void print() const {
        cout << "child : " << a << endl;
    }
    void childPrint() const {
        cout << "child only : " << a << endl;
    }
};


int main() {
    child c(8);
    parent *d = &c;
    d->parent::testset(11);
    c.print();
    d->print();
/*
    parent p(9);
    child * q = (child *)&p;
    q->print();
    q->childPrint();
*/
    return 0;
}