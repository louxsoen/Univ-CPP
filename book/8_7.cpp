#include <iostream>
#include <string>
using namespace std;

class BaseMemory {
    char *mem;
protected:
    BaseMemory(int size) { mem = new char [size]; }
    void set(char *x) { mem = x; }
    void put(int n, char put) { mem[n] = put; }
    char get(int n) { return mem[n]; }
};

class ROM : public BaseMemory {
public:
    ROM(int mem, char *arr, int size) : BaseMemory(size) { set(arr); }
    char read(int n) { char mem = get(n); return mem; }
};

class RAM : public BaseMemory {
public:
    RAM(int size) : BaseMemory(size) {;}
    void write(int n, char mem) { put(n, mem); }
    char read(int n) { char mem = get(n); return mem; }
};

int main()
{
    char x[5] = {'h', 'e', 'l', 'l', 'o'};
    ROM biosROM(1024*10, x, 5); // 10KB ROM 메모리. 배열 x로 초기화
    RAM mainMemory(1024*1024); // 1MB의 RAM 메모리
    
    for(int i = 0 ; i < 5 ; i++) mainMemory.write(i, biosROM.read(i));
    for(int i = 0 ; i < 5 ; i++) cout << mainMemory.read(i);
}
// 결과물 hello 여야함