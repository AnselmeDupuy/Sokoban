#include "sokoban.h"

int main()
{
	int goal_x = 0, goal_y = 0;
	int player_x = 0, player_y = 0;
	int box_x = 0, box_y = 0;

	int etat = 0;
	int move;

	char **board;
	int end = 0;

	board = init_board();

	while(end <= 10)
	{
		srand(time(NULL));

		if(etat == 0)
		{
			
			position(board, &goal_x, &goal_y, &player_x, &player_y, &box_x, &box_y);
			etat = 1;
		
		}
		else if(etat != 0)
		{
			display_board(board);	
			ask_player_move(board, &player_x, &player_y);

		}
	
		

		printf("Goal: %d, %d ", goal_x, goal_y);
		printf("\tplayer: %d, %d ", player_x, player_y);
		printf("\tbox: %d, %d ", box_x, box_y);
		

		end++;
	}
	free(board);


	return 0;
}