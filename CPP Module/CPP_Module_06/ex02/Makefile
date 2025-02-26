SRC = Base.cpp A.cpp B.cpp C.cpp func.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

CC = c++
CFLAGS = -Wextra -Wall -Werror -std=c++98

NAME = generater

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