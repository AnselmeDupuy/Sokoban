#include "sokoban.h"


char ** init_board()
{
	char ** board;
	int i;
	int j;

	i = 0;
	board = malloc(8 * sizeof(*board)); 

	while(i < 8)
	{
		board[i] = malloc(8 * sizeof(char)); 
		j = 0;

		while(j < 8)
		{
			board[i][j] = ' '; 
			j++;
		}

		i++;
	}

	return board;
}

void display_board(char **board)
{
	system("clear");
	int i;

	i = 0;

	printf("\n");

	printf("\t##########\n");
	while(i < 8)
	{

		if( i < 8)
		{
			printf("\t#%c%c%c%c%c%c%c%c#\n",board[i][0], board[i][1], board[i][2], board[i][3], board[i][4], board[i][5], board[i][6], board[i][7]);
		}

		i++;
	}
	printf("\t##########\n");
	printf("\n\n");
}

int position(char **board, int *goal_x, int *goal_y,int *player_x, int *player_y, int *box_x, int *box_y)
{
	int rand_box_y;
	int rand_box_x;

	int rand_y;
	int rand_x;

	int rand_goal_y;
	int rand_goal_x;


	rand_y = rand() % 8;
	rand_x = rand() % 8;

	char player = 'o';


	rand_box_y = (rand() % 5)+1;
	rand_box_x = (rand() % 5)+1;

	char box = 'X';


	rand_goal_y = rand() % 8;
	rand_goal_x = rand() % 8;

	char goal = '.';

	if((rand_goal_x == rand_x) && (rand_goal_y == rand_y))
	{
		rand_goal_y = rand() % 8;
		rand_goal_x = rand() % 8;
	}
	else if((rand_box_x == rand_x) && (rand_box_y == rand_y))
	{
		rand_box_y = (rand() % 5)+1;
		rand_box_x = (rand() % 5)+1;
	}
	else if((rand_box_x == rand_goal_x) && (rand_box_y == rand_goal_y))
	{
		rand_goal_y = rand() % 8;
		rand_goal_x = rand() % 8;
	}
	
	*goal_x = rand_goal_x;
	*goal_y = rand_goal_y;

	*player_x = rand_x;
	*player_y = rand_y;

	*box_x = rand_box_x;
	*box_y = rand_box_y;

	board[rand_goal_x][rand_goal_y] = goal;
	board[rand_x][rand_y] = player;
	board[rand_box_x][rand_box_y] = box;
	
}