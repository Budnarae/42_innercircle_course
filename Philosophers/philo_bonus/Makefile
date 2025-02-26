SRC = alloc_philo_stat_bonus.c free_struct_bonus.c main_bonus.c \
	philo_actions_bonus.c philo_actions_bonus_2.c philo_utils_bonus.c \
	philo_utils_bonus_2.c philosophers_bonus.c philosophers_bonus_2.c \
	philosophers_bonus_3.c utils_bonus.c utils_bonus_2.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wextra -Wall -Werror #-fsanitize=thread

NAME = philo_bonus

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) -g -o $(NAME) $(OBJ) 

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean :
		rm -rf $(OBJ)

fclean :
		rm -rf $(OBJ) $(NAME) bonus

re : 
		make fclean all