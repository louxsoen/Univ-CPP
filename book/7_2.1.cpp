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

    bool operator == (int price)
    {
        if(this->price == price)
        return true;
        else return false;
    }

    bool operator == (string title)
    {
        if(this->title == title)
        return true;
        else return false;
    }

    bool operator == (Book& a)
    {
        if(this->title == a.title && this->pages == a.pages && this->price == a.price)
        return true;
        else return false;
    }

    void show()
    {
        cout << this->title << " " << this->price << "원 " << this->pages << " 페이지" << endl;
    }
};

int main()
{
    Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
    if(a == 30000) cout << "정가 30000원" << endl;
    if(a == "명품 C++") cout << "명품 C++입니다." << endl;
    if(a == b) cout << "두 책이 같은 책입니다." << endl;
}