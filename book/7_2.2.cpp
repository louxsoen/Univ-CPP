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
    friend bool operator == (const Book a, int price);
    friend bool operator == (const Book a, string title);
    friend bool operator == (const Book a, const Book b);
};

bool operator == (const Book a, int price)
{
    if(a.price == price)
    return true;
    else return false;
}

bool operator == (const Book a, string title)
{
    if(a.title == title)
    return true;
    else return false;
}

bool operator == (const Book a, const Book b)
{
    if(b.title == a.title && b.pages == a.pages && b.price == a.price)
    return true;
    else return false;
}

int main()
{
    Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
    if(a == 30000) cout << "정가 30000원" << endl;
    if(a == "명품 C++") cout << "명품 C++입니다." << endl;
    if(a == b) cout << "두 책이 같은 책입니다." << endl;
}