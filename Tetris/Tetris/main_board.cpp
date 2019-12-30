#include"main_board.h"
#include"block.h"



int main_board::cursor_x = 3;
int main_board::cursor_y = 0;
bool main_board::blo[MAIN_Y][MAIN_X] = { 0 };
main_board::main_board() {
	this->cursor_x = 0;
	this->cursor_y = 0;
	this->block_falling = false;
	this->score = 0;
	this->level = 1;
}

//ó���� ���� ����� �Լ�
void main_board::printboard() {
	for (int i = 0; i < MAIN_Y; i++) {
		for (int j = 0; j < MAIN_X; j++) {
			if (i==MAIN_Y-1) {
				blo[i][j] = 1;
			}
			if (j == 0 || j == MAIN_X - 1) {
				blo[i][j] = 1;
			}
		}
	}
	set_cursor(BORDER_SPACE_X, BORDER_SPACE_Y+1);
	for (int i = 0; i < MAIN_Y; i++) {
		for (int j = 0; j < MAIN_X; j++) {
			if (blo[i][j] == true)
				cout << "��";
			else
				cout << "  ";
		}
		set_cursor(BORDER_SPACE_X, BORDER_SPACE_Y+i+1);
	}
}

//���� �������� �ִ��� Ȯ���ϴ� �Լ� ( �� ���� �ʿ��� ����ΰ�?  Ȯ�� �ʿ�  ��)
bool main_board::is_block_falling() {
	return this->block_falling;
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

void main_board::removeCursor(void)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

}

int main_board::get_cursor_x() {
	return this->cursor_x;
}

int main_board::get_cursor_y() {
	return this->cursor_y;
}

bool main_board::is_nextblo_true(int y,int x) {
	if (this->blo[y+1][x] == 1) {
		return true;
	}
	else return false;
}

bool main_board :: is_gameover() {

	return 0;//���� 1
}

//�� �� ä������ ����+������� �Լ�
bool main_board::blo_clear() {
	bool is_full;
	for (int i = 0; i < MAIN_Y-1; i++) {
		is_full = true;
		for (int j = 1; j < MAIN_X - 1; j++)
		{
			if (blo[i][j] == 0) //�ϳ��� ��ĭ�������� is_full=false
			{
				is_full = false;
				break;
			}
		}
		if (is_full) {  //��á���� �����, ���� �ø���
			for (int j = 1; j < MAIN_X - 1; j++)
			{
				blo[i][j] = 0;
			}
			for (int z = i; z > 0; z--)
			{
				for (int j = 1; j < MAIN_X - 1; j++)
				{
					if (blo[z - 1][j] == 1) {
						blo[z - 1][j] = 0;
						blo[z][j] = 1;
					}
				}

			}
			set_cursor(BORDER_SPACE_X, BORDER_SPACE_Y + 1);
			system("cls");
			set_cursor(BORDER_SPACE_X, BORDER_SPACE_Y + 1);
			for (int i = 0; i < MAIN_Y; i++) {
				for (int j = 0; j < MAIN_X; j++) {
					if (j==0||j==MAIN_X-1||i==MAIN_Y-1)
					{
						cout<<"��";
					}
					else
					{
						if (blo[i][j] == true)
							cout << "��";
						else
							cout << "  ";
					}
					
				}
				set_cursor(BORDER_SPACE_X, BORDER_SPACE_Y + i + 1);
			}
			this->score += 10;
		}
	}
	return false;
}

//�� ����� �� �������� �����ϴ� �Լ� �� Ŭ������ ���� ���. �̸� �ٲ����
int main_board::block_created() {
	this->block_falling = true;
	block *Pblock = new block();
	Pblock->createBlock();
	int key;
	
	while (1) {
		Pblock->showBlock();
		for (int i = 0; i < 7; i++) {
			
			if (_kbhit()) {
				key = _getch();
				Pblock->block_control(key);
			}
			Sleep(100);
		}
		if (Pblock->isGround())
		{
			this->block_falling = false;
			Pblock->saveBlock(blo);// ���� ���� blo�� �����ؾ���
			blo_clear();
			return 0;
		}
		else
		{
			Pblock->removeBlock();
			set_cursor(get_cursor_x(), get_cursor_y() + 1);
		}
		
	}
	return 0;
}
