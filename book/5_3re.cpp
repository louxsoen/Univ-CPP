#include <iostream>
#include <string>
using namespace std;

void combine(const string a, const string b, string &c)
{
    c = a;
    c.append(" ");
    c.append(b);
}

int main()
{
    string text1("I love you"), text2("very much");
    string text3;
    combine(text1, text2, text3);
    cout << text3;
}