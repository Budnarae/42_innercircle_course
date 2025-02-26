SRC = most_basic.c most_basic_2.c utils.c operations.c utils_2.c check_dup.c check_dup_utils.c
OBJ = $(SRC:.c=.o)
MEN_SRC = push_swap.c push_swap_2.c push_swap_3.c push_swap_4.c push_swap_5.c push_swap_6.c hardcase.c
MEN_OBJ = $(MEN_SRC:.c=.o)
BONUS_SRC = checker.c
BONUS_OBJ = checker.o

CC = cc
CFLAGS = -Wextra -Wall -Werror

NAME = push_swap
BONUS_NAME = checker

$(NAME) : $(MEN_OBJ) $(OBJ)
		make -C ./libft/ all bonus
		$(CC) $(CFLAGS) -g -o $(NAME) -Llibft/ $(MEN_OBJ) $(OBJ) -lft

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

bonus : $(BONUS_OBJ) $(OBJ)
		make -C ./libft/ all bonus
		$(CC) $(CFLAGS) -g -o $(BONUS_NAME) -Llibft/ $(BONUS_OBJ) $(OBJ) -lft
		touch $@

clean :
		rm -rf $(OBJ) $(MEN_OBJ) $(BONUS_OBJ)
		make -C ./libft/ clean

fclean :
		rm -rf $(OBJ) $(MEN_OBJ) $(BONUS_OBJ) $(NAME) $(BONUS_NAME) bonus
		make -C ./libft/ fclean

re : 
		make fclean all