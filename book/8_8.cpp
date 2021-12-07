#include <iostream>
#include <string>
using namespace std;

class Printer {
    string model;
    string manufacturer;
    int printedCount;
    int availableCount;
public:
    Printer() { }
    void print(int pages)
    {
        if(availableCount < pages)
        cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
        else
        {
            availableCount -= pages;
            cout << "프린트하였습니다." << endl;
        }
    }
    void set_info(string model = "NONE", string manufacturer = "NONE")
    {
        this->model = model;
        this->manufacturer = manufacturer;
    }
    void set_state(int paper)
    {
        this->availableCount = paper;
    }
    string get_model() { return model; }
    string get_manufacturer() { return manufacturer; }
    int get_paperNum() { return availableCount; }
};

class InkJetPrinter : public Printer {
    int availableInk;
public:
    InkJetPrinter() 
    { 
        set_info("Officejet V40", "HP"); 
        set_state(5);
        availableInk = 10;
    }
    void printfInkJet(int pages)
    {
        if(availableInk < pages)
        cout << "잉크가 부족하여 프린트 할 수 없습니다." << endl;
        else
        {
            availableInk -= pages;
            print(pages);
        }
            
    }
    int get_Ink() { return availableInk; }
};

class LaserPrinter : public Printer {
    int availableToner;
public:
    LaserPrinter() 
    { 
        set_info("SCX-6x45", "삼성전자"); 
        set_state(3);
        availableToner = 20;
    }
    void printLaser(int pages)
    {
        if(availableToner < pages)
        cout << "토너가 부족하여 프린트 할 수 없습니다." << endl;
        else
        {
            availableToner -= pages;
            print(pages);
        }   
    }
    int get_Toner() { return availableToner; }
};

int main()
{
    LaserPrinter Samsung;
    InkJetPrinter HP;
    int type, pages;
    char keep = 'y';
    cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
    cout << "잉크젯 : " << HP.get_model() << " ," << HP.get_manufacturer() << " ,남은 종이 " << HP.get_paperNum() << "장 , 남은 잉크 " << HP.get_Ink() << endl;
    cout << "레이저 : " << Samsung.get_model() << " ," << Samsung.get_manufacturer() << " ,남은 종이 " << Samsung.get_paperNum() << "장 , 남은 잉크 " << Samsung.get_Toner() << endl;

    while(keep == 'y')
    {
        cout << endl;
        cout << "프린터(1:잉크젯, 2:레이저)와 매수입력>>";
        cin >> type >> pages;
        
        if(type == 1) HP.printfInkJet(pages);
        else if(type == 2) Samsung.printLaser(pages);
        else cout << "잘못 입력하셨습니다." << endl;
        cout << HP.get_model() << " ," << HP.get_manufacturer() << " ,남은 종이 " << HP.get_paperNum() << "장 , 남은 잉크 " << HP.get_Ink() << endl;
        cout << Samsung.get_model() << " ," << Samsung.get_manufacturer() << " ,남은 종이 " << Samsung.get_paperNum() << "장 , 남은 잉크 " << Samsung.get_Toner() << endl;
        
        cout << "계속 프린트 하시겠습니까(y/n)";
        cin >> keep;
    }
}