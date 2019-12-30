#include "block.h"

using namespace std;
bool block_shape[7][4][4][4] = //[���][����][y][x]
{
	//  ���
	//    ���
	{
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,0,1,1},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,0,1,0},
			{0,1,1,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,0,1,1},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,0,1,0},
			{0,1,1,0},
			{0,1,0,0}
		}
	},
	//    ���
	//  ���
	{
		{
			{0,0,0,0},
			{0,1,1,0},
			{1,1,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,0,0,0},
			{1,1,0,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{1,1,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,0,0,0},
			{1,1,0,0},
			{0,1,0,0}
		}
	},
	// �����
	{
		{
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,1}
		},
		{
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,1}
		}
	},
	//  ���
	//  ���
	{
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		}
	},
	//  ��
	//  ����
	{
		{
			{0,0,0,0},
			{1,0,0,0},
			{1,1,1,0},
			{0,0,0,0}
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
	//      ��
	//  ����
	{
		{
			{0,0,0,0},
			{0,0,1,0},
			{1,1,1,0},
			{0,0,0,0}
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
	//   ��
	// ����
	{
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,1,0},
			{0,0,0,0}
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


//
void block::cursor_clr()
{
	if (this->new_block_shape == 2)
		set_cursor(3+BORDER_SPACE_X, 1+BORDER_SPACE_Y);
	else
		set_cursor(3+BORDER_SPACE_X, 0+BORDER_SPACE_Y);
}

//�� �����Լ�
void block::createBlock()
{
	srand(time(0));
	this->new_block_shape = rand() % 7; //�������� �ٲ����
	cursor_clr();
}

//���� ��Ÿ���� �Լ�
void block::showBlock()
{
	int x = get_cursor_x();
	int y = get_cursor_y();
	int cy = y;
	

	set_cursor(x, y);
	for (int i = 0; i < 4; i++)
	{
		int cx = x;
		set_cursor_onlyconsole(x, y); //xĿ�� �ʱ�ȭ
		for (int j = 0; j < 4; j++)
		{
			if (block_shape[this->new_block_shape][this->new_block_turn][i][j] == 1) {
				cout << "��";
			}
			cx++;
			set_cursor_onlyconsole(cx, y);  //xĿ�� ��ĭ ������
		}
		set_cursor_onlyconsole(cx, ++y); //yĿ�� ��ĭ ������
	}
}

//���� �� �������� �� ���� �����ϴ� �Լ�
void block::saveBlock(bool(*blo)[11]) {
	int x = get_cursor_x();
	int y = get_cursor_y();
	x -= BORDER_SPACE_X;
	y -= BORDER_SPACE_Y;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{

			if (block_shape[this->new_block_shape][this->new_block_turn][i][j] == 1) {
				blo[i + y][j + x] = true;
			}

		}
	}
	cursor_clr();

}



//���� �����϶� �����ִ� �� �����ϴ� �Լ�
void block::removeBlock()
{
	int x = get_cursor_x();
	int y = get_cursor_y();

	int cy = y;
	for (int i = 0; i < 4; i++)
	{
		int cx = x;
		set_cursor_onlyconsole(x, y); //xĿ�� �ʱ�ȭ
		for (int j = 0; j < 4; j++)
		{
			if (block_shape[this->new_block_shape][this->new_block_turn][i][j] == 1) {
				cout << "  ";
			}
			cx++;
			set_cursor_onlyconsole(cx, y);  //xĿ�� ��ĭ ������
		}
		set_cursor_onlyconsole(cx, ++y); //yĿ�� ��ĭ ������
	}
}

//y+1ĭ�� ä�����ִ� ĭ���� Ȯ���ϴ� �Լ�
bool block::isGround() {
	int x = get_cursor_x();
	int y = get_cursor_y();
	x -= BORDER_SPACE_X;
	y -= BORDER_SPACE_Y;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) {
			if (block_shape[this->new_block_shape][this->new_block_turn][i][j] == 1)
			{
				if (is_nextblo_true(y+i, x+j)) {
					return true;
				}
			}

		}
	}
	return false;
}

void block::block_control(int key){
	if (key == 224)
	{
		key = _getch();
		
		switch (key) {
		case 72: //��
			this->rotate_block(get_cursor_x(), get_cursor_y());
			break;
		case 75: //��
			if(!this->is_border(get_cursor_x() - 1,get_cursor_y()))
			{
				this->removeBlock();
				set_cursor(get_cursor_x() - 1, get_cursor_y());
				this->showBlock();
			}
			break;
		case 77: //��
			if (!this->is_border(get_cursor_x() + 1, get_cursor_y()))
			{
				this->removeBlock();
				set_cursor(get_cursor_x() + 1, get_cursor_y());
				this->showBlock();
			}
			break;
		case 80: //��
			if (!this->is_border(get_cursor_x(), get_cursor_y()+1))
			{
				this->removeBlock();
				set_cursor(get_cursor_x(), get_cursor_y() + 1);
				this->showBlock();
			}
			break;
		case 32:
			this->removeBlock();
			while (!isGround())
			{
				set_cursor(get_cursor_x(), get_cursor_y() + 1);
			}
			this->showBlock();
			break;
		default:
			break;
		}
	}
	else
	{
		switch (key) 
		{
		case 32:
			this->removeBlock();
			while (!isGround())
			{
				set_cursor(get_cursor_x(), get_cursor_y() + 1);
			}
			this->showBlock();
			break;
		default:
			break;
		}
	}
}

void block::rotate_block(int x, int y) {
	int tmp_rotate = (this->new_block_turn+1)%4;
	if (!is_border(x, y, tmp_rotate)) {
		this->removeBlock();
		this->new_block_turn = tmp_rotate;
		this->showBlock();
	}
}

bool block::is_border(int x ,int y ) {
	x -= BORDER_SPACE_X;
	y -= BORDER_SPACE_Y;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) {
			if (block_shape[this->new_block_shape][this->new_block_turn][i][j] == 1)
			{
				if (is_nextblo_true(y+i-1, x + j)) {
					return true;
				}
			}

		}
	}
	return false;
}

bool block::is_border(int x, int y, int rotation) {
	x -= BORDER_SPACE_X;
	y -= BORDER_SPACE_Y;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) {
			if (block_shape[this->new_block_shape][rotation][i][j] == 1)
			{
				if (is_nextblo_true(y + i-1, x + j)) {
					return true;
				}
			}

		}
	}
	return false;
}