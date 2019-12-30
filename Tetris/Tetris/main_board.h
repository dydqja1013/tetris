#pragma once
#define LEFT 75 //좌로 이동    //키보드값들 
#define RIGHT 77 //우로 이동 
#define UP 72 //회전 
#define DOWN 80 //soft drop
#define MAIN_X 11 //게임판 가로크기 
#define MAIN_Y 23 //게임판 세로크기 
#define x_border
class main_board {
private:
	static bool blo[MAIN_Y][MAIN_X];
	static int cursor_x;
	static int cursor_y;
	bool block_falling; //블럭이 내려가고있는지
public:
	main_board();
	void printboard();
	void cursor_clr();
	bool is_block_falling();
	void block_created();
	void set_cursor(int, int);
	void set_cursor_onlyconsole(int, int);
	int get_cursur_x();
	int get_cursur_y();
	bool is_nextblo_true(int,int);
};