#pragma once

#include "main_board.h"

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
};

