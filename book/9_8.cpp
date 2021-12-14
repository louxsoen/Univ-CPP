#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    string name; // 도형 이름
    int width, height; // 너비, 높이
public:
    Shape(string n = "", int w=0, int h=0) { name = n ; width = w; height = h; }
    virtual double getArea() { return 0; }
    string getName() { return name; }
};

class Oval : public Shape { // 타원
public:
    Oval(string name, int x, int y) : Shape(name, x, y) { getArea(); }
    virtual double getArea() { return width * height * 3.14; }
};

class Rect : public Shape { // 사각형
public:
    Rect(string name, int x, int y) : Shape(name, x, y) { getArea(); }
    virtual double getArea() { return width * height; }
};

class Triangular : public Shape { // 타원
public:
    Triangular(string name, int x, int y) : Shape(name, x, y) { getArea(); }
    virtual double getArea() { return width * height / 2; }
};

int main()
{
    Shape *p[3];
    p[0] = new Oval("빈대떡", 10, 20);
    p[1] = new Rect("찰떡", 30, 40);
    p[2] = new Triangular("토스트", 30, 40);

    for(int i = 0 ; i < 3 ; i++)
    cout << p[i]->getName() << "넓이는 " << p[i]->getArea() << endl;

    for(int i = 0 ; i < 3 ; i++)
    delete p[i];
}