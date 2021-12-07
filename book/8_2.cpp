#include <iostream>
#include <string>
using namespace std;

class Circle {
    int radius;
public:
    Circle(int radius = 0) { this->radius = radius; }
    int getRadius() { return radius; }
    void setRadius(int radius) { this->radius = radius; }
    double getArea() { return 3.14 * radius * radius; }
};

class NamedCircle : public Circle {
    string name;
public:
    void set(int radius, string name) { setRadius(radius); this->name = name; }
    void show() { cout << "반지름이 " << getRadius() << "인 " << name << endl; }
    string getName() { return this->name; }
};

int main()
{
    int radius, size[5];
    string name;
    NamedCircle pizza[5];
    cout << "5 개의 정수 반지름과 원의 이름을 입력하세요" << endl;
    for(int i = 0 ; i < 5 ; i++)
    {
        cout << i + 1 << ">> ";
        cin >> radius >> name;
        pizza[i].set(radius, name);
    }
    string max;
    for(int i = 0 ; i < 4 ; i++)
    {
        if(pizza[i].getArea() > pizza[i + 1].getArea())
        max = pizza[i].getName();
    }
    cout << "가장 면적이 큰 피자는 " << max << "입니다" << endl;
}