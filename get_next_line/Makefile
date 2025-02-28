SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)
BONUS_SRC = get_next_line_bonus.c get_next_line_utils_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)


NAME = libgnl.a

$(NAME) : $(OBJ)
		ar -rc $(NAME) $(OBJ)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

bonus : $(BONUS_OBJ)
		ar -rc $(NAME) $(BONUS_OBJ)
		touch $@

clean :
		rm -rf $(OBJ) $(BONUS_OBJ)

fclean :
		rm -rf $(OBJ) $(BONUS_OBJ) $(NAME) bonus

re : 
		make fclean all