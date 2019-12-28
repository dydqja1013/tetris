#pragma once
#define LEFT 75 //�·� �̵�    //Ű���尪�� 
#define RIGHT 77 //��� �̵� 
#define UP 72 //ȸ�� 
#define DOWN 80 //soft drop
#define MAIN_X 11 //������ ����ũ�� 
#define MAIN_Y 23 //������ ����ũ�� 
class main_board {
private:
	bool blo[MAIN_Y][MAIN_X];
	int cursor_x;
	int cursor_y;
	bool block_falling; //���� ���������ִ���
public:
	main_board();
	void printboard();
	void cursor_clr();
	bool is_block_falling();
	void block_created();
	void set_cursor(int, int);
	int get_cursur_x();
	int get_cursur_y();
};