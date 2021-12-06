#include <iostream>
#include <string>
using namespace std;

class Board
{
public:
    static string board[100];
    static int board_id;
    static void add(string a)
    {
        board[board_id] = a;
        board_id++;
    }
    static void print()
    {
        cout << "************ 게시판입니다. ************" << endl;
        for(int i = 0 ; i < board_id ; i++)
        cout << i << ": " << board[i] << endl;

        cout << endl;
    }
        
};

int Board::board_id = 0;
string Board::board[100];

int main()
{
    // Board myBoard;
    Board::add("중간고사는 감독 없는 자율 시험입니다.");
    Board::add("코딩 라운지 많이 이용해주세요.");
    Board::print();

    Board::add("louxsoen 학생이 c++ 교수님에게 반항을 했습니다. 축하해주세요.");
    Board::print();
}