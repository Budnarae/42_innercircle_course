SRC = main.c parse_args.c parse_args_2.c utils.c utils_2.c pipex.c
OBJ = $(SRC:.c=.o)
BONUS_SRC = main_bonus.c parse_args_bonus.c parse_args_2_bonus.c utils_bonus.c utils_2_bonus.c pipex_bonus.c pipex_2_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

CC = cc
CFLAGS = -Wextra -Wall -Werror -g
LIBFTFLAGS = -Llibft/ -lft

NAME = pipex

$(NAME) : $(OBJ)
		make -C ./libft/ all bonus
		$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFTFLAGS) -g -o $(NAME) $(OBJ) 

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

bonus : $(BONUS_OBJ)
		make -C ./libft/ all bonus
		$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFTFLAGS) -g -o $(NAME) $(BONUS_OBJ)
		touch $@

clean :
		rm -rf $(OBJ) $(BONUS_OBJ)
		make -C ./libft/ clean

fclean :
		rm -rf $(OBJ) $(BONUS_OBJ) $(NAME) bonus
		make -C ./libft/ fclean

re : 
		make fclean all