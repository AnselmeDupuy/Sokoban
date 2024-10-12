# Makefile

NAME = Sokoban

SRCS = Sokoban.c \
		moves.c \
		board.c \
		sokoban.h

all :  $(NAME)

$(NAME): $(SRCS)
	gcc $(SRCS) -o $(NAME)

fclean: 
	rm -f $(NAME)

re: fclean all