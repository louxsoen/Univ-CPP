#include <iostream>
#include <string>
using namespace std;

class Trace
{

public:
    static string taginfo[100];
    static string debuginfo[100];
    static int n;
    static void put(string tag, string debug)
    {
        taginfo[n] = tag;
        debuginfo[n] = debug;
        n++;
    }
    static void print(string tag = "all")
    {
        if(tag == "all")
        {
            cout << "----- 모든 Trace 정보를 출력합니다. -----" << endl;
            for(int i = 0 ; i < n ; i++)
            cout << taginfo[i] << ":" << debuginfo[i] << endl;
        }
        else
        {
            cout << "----- f() 태그의 Trace 정보를 출력합니다. -----" << endl;
            for(int i = 0 ; i < n ; i++)
            if(taginfo[i] == tag)
            cout << taginfo[i] << ":" << debuginfo[i] << endl;
        }
    }
};

int Trace::n = 0;
string Trace::taginfo[100];
string Trace::debuginfo[100];

void f()
{
    int a, b, c;
    cout << "두 개의 정수를 입력하세요>>";
    cin >> a >> b;
    Trace::put("f()", "정수를 입력 받았음");
    c = a + b;
    Trace::put("f()", "합 계산");
    
    cout << "합은 " << c << endl;
}

int main()
{
    Trace::put("main()", "프로그램을 시작합니다");
    f();
    Trace::put("main()", "종료");
    Trace::print("f()");
    Trace::print();
}