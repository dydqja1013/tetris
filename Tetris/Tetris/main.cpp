
#include"block.h"
#include"main_board.h"
#include<cstdio>


int main() {
	main_board *Pgame = new main_board();
	Pgame->removeCursor();
	Pgame->printboard();
	getchar();
	while (1)
	{
		
		Pgame->block_created();
		if (Pgame->is_gameover())
		{
			Sleep(100);
			system("cls");
			cout << "gameover";
		}
	}
}