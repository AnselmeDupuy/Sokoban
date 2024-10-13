#include "sokoban.h"

void ask_player_move(char **board, int *player_x, int *player_y,int *end) 
{
    char input;
    printf("Entrer le movement (z/s/q/d) :\n");
    scanf(" %c", &input); 

    int x_temp = *player_x;
    int y_temp = *player_y;

    if (input == 'z') 
    {
    	x_temp--;
    }
    else if (input == 's')
    {
    	x_temp++;
    } 
    else if (input == 'q') 
    {
    	y_temp--;
   	}
	else if (input == 'd') 
    {
    	y_temp++;
	}

	if (x_temp >= 0 && x_temp < 8 && y_temp >= 0 && y_temp < 8) 
    {
    	if(board[x_temp][y_temp] == 'X')
    	{
    		
    		int box_tempo_x = x_temp + (x_temp - *player_x);
    		int box_tempo_y = y_temp + (y_temp - *player_y);
    		board[box_tempo_x][box_tempo_y] = 'X';
    		board[*player_x][*player_y] = ' ';
    		*player_x = x_temp;
			*player_y = y_temp;
			board[x_temp][y_temp] = ' ';
			board[x_temp][y_temp] = 'o';

			if(board[x_temp][y_temp] == '.')
			{
				printf("Gagné!");
				*end = 1;
			}
    	}
        else if (board[x_temp][y_temp] == ' ') 
        {
			board[*player_x][*player_y] = ' '; 
			*player_x = x_temp;
			*player_y = y_temp;
			board[x_temp][y_temp] = 'o';
        }
        else if(board[x_temp][y_temp] == '.')
        {
        	board[*player_x][*player_y] = ' '; 
        	*player_x = x_temp;
			*player_y = y_temp;
			board[x_temp][y_temp] = 'o';
        }
        else 
        {
			printf("obstacle");
        }
    } else 
    {
        printf("movement impossible");
    }
}

