#pragma once
#define LEFT 75 //좌로 이동    //키보드값들 
#define RIGHT 77 //우로 이동 
#define UP 72 //회전 
#define DOWN 80 //soft drop
#define MAIN_X 11 //게임판 가로크기 
#define MAIN_Y 23 //게임판 세로크기 
#define BORDER_SPACE_X 3
#define BORDER_SPACE_Y 2
#include<Windows.h>
#include<iostream>
#include<conio.h>
using namespace std;
class main_board {
private:
	static bool blo[MAIN_Y][MAIN_X];
	static int cursor_x;
	static int cursor_y;
	bool block_falling; //블럭이 내려가고있는지
	int score;
	int level;
public:
	main_board();
	void printboard();
	bool is_block_falling();
	int block_created();
	void set_cursor(int, int);
	void set_cursor_onlyconsole(int, int);
	int get_cursor_x();
	int get_cursor_y();
	bool is_nextblo_true(int,int);
	bool blo_clear();
	void removeCursor();
	bool is_gameover();
};