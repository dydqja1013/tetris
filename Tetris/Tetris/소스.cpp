#include<iostream>
#include<Windows.h>



#define LEFT 75 //좌로 이동    //키보드값들 
#define RIGHT 77 //우로 이동 
#define UP 72 //회전 
#define DOWN 80 //soft drop
#define MAIN_X 11 //게임판 가로크기 
#define MAIN_Y 23 //게임판 세로크기 

using namespace std;


class main_board {
private:
	bool blo[MAIN_Y][MAIN_X] = { 0 };
public:
	main_board() {};
	void printboard() {
		Sleep(1000);
		system("cls");
		for (int i = 0; i < MAIN_Y; i++) {
			for (int j = 0; j < MAIN_X; j++) {
				if (blo[i][j] == true)
					cout << "■";
				else
					cout << "□";
			}
			cout << endl;
			this->blo[0][0] = 1;
			this->blo[5][5] = 1;
		}
	}
};






int main() {
	main_board *game = new main_board();
	while (1)
	{

		game->printboard();
	}
}