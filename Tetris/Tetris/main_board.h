#pragma once
#define LEFT 75 //�·� �̵�    //Ű���尪�� 
#define RIGHT 77 //��� �̵� 
#define UP 72 //ȸ�� 
#define DOWN 80 //soft drop
#define MAIN_X 11 //������ ����ũ�� 
#define MAIN_Y 23 //������ ����ũ�� 
#define x_border
class main_board {
private:
	static bool blo[MAIN_Y][MAIN_X];
	static int cursor_x;
	static int cursor_y;
	bool block_falling; //���� ���������ִ���
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