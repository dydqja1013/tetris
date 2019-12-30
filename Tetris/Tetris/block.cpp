#include "block.h"
#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
bool block_shape[7][4][4][4] = //[모양][각도][y][x]
{
	//  ■■
	//    ■■
	{
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,1,1,0},
			{0,0,1,1}
		},
		{
			{0,0,0,0},
			{0,0,1,0},
			{0,1,1,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,1,1,0},
			{0,0,1,1}
		},
		{
			{0,0,0,0},
			{0,0,1,0},
			{0,1,1,0},
			{0,1,0,0}
		}
	},
	//    ■■
	//  ■■
	{
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,1,1,0},
			{1,1,0,0}
		},
		{
			{0,0,0,0},
			{1,0,0,0},
			{1,1,0,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,1,1,0},
			{1,1,0,0}
		},
		{
			{0,0,0,0},
			{1,0,0,0},
			{1,1,0,0},
			{0,1,0,0}
		}
	},
	// ■■■■
	{
		{
			{0,0,1,0},
			{0,0,1,0},
			{0,0,1,0},
			{0,0,1,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,1}
		},
		{
			{0,0,1,0},
			{0,0,1,0},
			{0,0,1,0},
			{0,0,1,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,1}
		}
	},
	//  ■■
	//  ■■
	{
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0}
		}
	},
	//  ■
	//  ■■■
	{
		{
			{0,0,0,0},
			{0,0,0,0},
			{1,0,0,0},
			{1,1,1,0}
		},
		{
			{0,0,0,0},
			{1,1,0,0},
			{1,0,0,0},
			{1,0,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,0},
			{0,0,1,0}
		},
		{
			{0,0,0,0},
			{0,0,1,0},
			{0,0,1,0},
			{0,1,1,0}
		}
	},
	//      ■
	//  ■■■
	{
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,0,1,0},
			{1,1,1,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,1,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,0},
			{1,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,0,1,0},
			{0,0,1,0}
		}
	},
	//   ■
	// ■■■
	{
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,1,0,0},
			{1,1,1,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{0,1,1,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,0,0},
			{0,1,0,0}
		}
	}
};

block::block()
{
	this->new_block_turn = 0;
	this->new_block_shape = 0;
}


block::~block()
{
}
void block::cursor_clr()
{
	if (this->new_block_shape == 2)
		set_cursor(3, 0);
	else
		set_cursor(3, -2);
}

void block::createBlock()
{
	srand(time(0));
	this->new_block_shape = rand() % 7; //랜덤으로 바꿔야함
	cursor_clr();
}

void block::showBlock()
{
	int x = get_cursur_x();
	int y = get_cursur_y();
	int cy = y;
	set_cursor(x, y);
	for (int i = 0; i < 4; i++)
	{
		int cx = x;
		set_cursor_onlyconsole(x, y); //x커서 초기화
		for (int j = 0; j < 4; j++)
		{
			if (block_shape[this->new_block_shape][this->new_block_turn][i][j] == 1) {
				cout << "■";
			}
			cx++;
			set_cursor_onlyconsole(cx, y);  //x커서 한칸 오른쪽
		}
		set_cursor_onlyconsole(cx, ++y); //y커서 한칸 내리기
	}
}

void block::removeBlock()
{
	int x = get_cursur_x();
	int y = get_cursur_y();

	int cy = y;
	set_cursor(x, y);
	for (int i = 0; i < 4; i++)
	{
		int cx = x;
		set_cursor_onlyconsole(x, y); //x커서 초기화
		for (int j = 0; j < 4; j++)
		{
			if (block_shape[this->new_block_shape][this->new_block_turn][i][j] == 1) {
				cout << "□";
			}
			cx++;
			set_cursor_onlyconsole(cx, y);  //x커서 한칸 오른쪽
		}
		set_cursor_onlyconsole(cx, ++y); //y커서 한칸 내리기
	}
}

bool block::isGround() {
	int x = get_cursur_x();
	int y = get_cursur_y();
	y = y + 3;
	for (int j = 0; j < 4; j++) {

		if (block_shape[this->new_block_shape][this->new_block_turn][y][j] == 1)
		{
			if (is_nextblo_true(y,x+j))
			{
				return true;
			}
		}

	}
	return false;
}