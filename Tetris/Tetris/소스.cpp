#include<iostream>
#include<Windows.h>
using namespace std;
class block {

};

class board {
private:
	int blo[20][10] = { 0 };
public:
	board() {};
	void printboard() {
		Sleep(1000);
		system("cls");
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 10; j++) {
				if (blo[i][j] == 1)
					cout << "бс";
				else
					cout << "бр";
			}
			cout << endl;
			this->blo[5][1] = 1;
			this->blo[5][5] = 1;
		}
	}
};








int main() {
	board *game = new board();
	while (1)
	{
		game->printboard();
	}
}