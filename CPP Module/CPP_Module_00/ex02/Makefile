SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)

CC = c++
CFLAGS = -Wextra -Wall -Werror -std=c++98

NAME = bank

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