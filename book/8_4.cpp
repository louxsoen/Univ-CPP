#include <iostream>
#include <string>
using namespace std;

class Point {
    int x, y;
public:
    Point(int x = 0, int y = 0) { this->x = x; this->y = y; }
    int getX() { return this->x; }
    int getY() { return this->y; }
protected:
    void move(int x, int y) { this->x = x; this->y = y; }
};

class ColorPoint : Point {
    string color;
public:
    ColorPoint(int x = 0, int y = 0, string color = "BLACK")
    {
        move(x, y);
        this->color = color;
    }
    void setColor(string color = "BLACK") { this->color = color; }
    void setPoint(int x = 0, int y = 0) { move(x, y); }
    void show() { cout << color << "색으로 (" << getX() << "," << getY() << ")에 위치한 점입니다." << endl; }
};

int main()
{
    ColorPoint zeroPoint;
    zeroPoint.show();
    
    ColorPoint cp(5, 5);
    cp.setPoint(10, 20);
    cp.setColor("BLUE");
    cp.show();
}