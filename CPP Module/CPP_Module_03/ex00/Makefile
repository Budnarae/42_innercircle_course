SRC = main.cpp ClapTrap.cpp
OBJ = $(SRC:.cpp=.o)

CC = c++
CFLAGS = -Wextra -Wall -Werror -std=c++98

NAME = claptrap

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) 

.cpp.o:
		$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean :
		rm -rf $(OBJ)

fclean :
		rm -rf $(OBJ) $(NAME)

re : 
		make fclean all