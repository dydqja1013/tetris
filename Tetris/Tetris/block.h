#pragma once

#include "main_board.h"
#include<iostream>
#include <stdlib.h>
#include <time.h>
#include<conio.h>
class block:public main_board
{
private:
	int new_block_shape;
	int new_block_turn;
	int next_block_shape;
public:
	block();
	~block();
	void createBlock();
	void showBlock();
	void removeBlock();
	void cursor_clr();
	bool isGround();
	void saveBlock(bool(*blo)[11]);
	void block_control(int);
	bool is_border(int, int);
	bool is_border(int, int, int);
	void rotate_block(int, int);
};

