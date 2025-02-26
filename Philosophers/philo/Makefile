SRC = alloc_philo_stat.c free_struct.c main.c philosophers.c philosophers_2.c \
	philo_actions.c philo_actions_2.c philo_utils.c philo_utils_2.c utils.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wextra -Wall -Werror #-fsanitize=thread

NAME = philo

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