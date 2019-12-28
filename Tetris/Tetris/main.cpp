
#include"block.h"
#include"main_board.h"




int main() {
	main_board *Pgame = new main_board();

	Pgame->printboard();
	while (1)
	{
		if (!Pgame->is_block_falling())
		{
			Pgame->block_created();
		}
	}
}