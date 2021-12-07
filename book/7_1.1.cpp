#include <iostream>
#include <string>
using namespace std;

class Book
{
    string title;
    int price;
    int pages;
public:
    Book(string title = "", int price = 0, int pages = 0)
    {
        this->title = title;
        this->price = price;
        this->pages = pages;
    }

    void operator += (int val)
    {
        this->price += val;
    }

    void operator -= (int val)
    {
        this->price -= val;
    }

    void show()
    {
        cout << this->title << " " << this->price << "원 " << this->pages << " 페이지" << endl;
    }
};

int main()
{
    Book a("청춘", 20000, 300), b("미래", 30000, 500);
    a += 500;
    b -= 500;
    a.show();
    b.show();
}