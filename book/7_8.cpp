#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle(int radius = 0) { this->radius = radius; }
    void show() { cout << "radius = " << radius << " 인 원" << endl; }
    friend Circle operator ++(Circle &a, int bin);
    friend Circle operator ++(Circle &a);
};

Circle operator ++(Circle &a)
{
    a.radius += 1;
    return a;
}

Circle operator ++(Circle &a, int bin)
{
    Circle c = a;
    a.radius += 1;
    return c;
}

int main()
{
    Circle a(5), b(4);
    ++a;
    b = a++;
    a.show();
    b.show();
}