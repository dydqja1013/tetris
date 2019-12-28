#include"main_board.h"
#include"block.h"
#include<Windows.h>
#include<iostream>
using namespace std;

int main_board::cursor_x = 3;
int main_board::cursor_y = 0;

main_board::main_board() {
	this->cursor_x = 0;
	this->cursor_y = 0;
	this->block_falling = false;
}

void main_board::printboard() {
	for (int i = 0; i < MAIN_Y; i++) {
		for (int j = 0; j < MAIN_X; j++) {
			if (blo[i][j] == true)
				cout << "бс";
			else
				cout << "бр";
		}
		cout << endl;
	}
}

void main_board::cursor_clr() {
	set_cursor(3, 0);
}

bool main_board::is_block_falling() {
	return this->block_falling;
}

void main_board::block_created() {
	this->block_falling = true;
	block *Pblock = new block();
	Pblock->createBlock();
	while (1) {
		Sleep(500);
		Pblock->removeBlock();
		set_cursor(get_cursur_x(), get_cursur_y() + 1);
		Pblock->showBlock();
	}
}

void main_board::set_cursor(int x, int y) {
	this->cursor_x = x;
	this->cursor_y = y;
	COORD Cur;
	Cur.X = x*2;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void main_board::set_cursor_onlyconsole(int x, int y) {
	COORD Cur;
	Cur.X = x * 2;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}


int main_board::get_cursur_x() {
	return this->cursor_x;
}

int main_board::get_cursur_y() {
	return this->cursor_y;
}