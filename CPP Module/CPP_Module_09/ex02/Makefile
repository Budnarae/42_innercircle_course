SRC = main.cpp PmergeMe.cpp PmergeMeWithList.cpp InputArrayParser.cpp NoneInputException.cpp Prover.cpp
OBJ = $(SRC:.cpp=.o)

CC = c++
CFLAGS = -Wextra -Wall -Werror -std=c++98 #-fsanitize=address

NAME = PmergeMe

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