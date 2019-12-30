#pragma once
#define LEFT 75 //�·� �̵�    //Ű���尪�� 
#define RIGHT 77 //��� �̵� 
#define UP 72 //ȸ�� 
#define DOWN 80 //soft drop
#define MAIN_X 11 //������ ����ũ�� 
#define MAIN_Y 23 //������ ����ũ�� 
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
	bool block_falling; //���� ���������ִ���
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