SRC = form_flag_width.c form_percent.c form_precision.c form_sign.c form_string.c ft_printf.c print_hex_form.c set_conditions.c ft_uitoa.c

OBJ = $(SRC:.c=.o)

BONUSSRC = form_flag_width_bonus.c form_percent_bonus.c form_precision_bonus.c form_sign_bonus.c form_string_bonus.c ft_printf_bonus.c print_hex_form_bonus.c set_conditions_bonus.c ft_uitoa_bonus.c
BONUSOBJ = $(BONUSSRC:.c=.o)

CC = cc
CFLAGS = -c -Wextra -Wall -Werror

NAME = libftprintf.a

$(NAME) : $(OBJ)
		ar -rc $(NAME) $(OBJ)
		make -f ./libft/Makefile all bonus

.c.o:
		$(CC) $(CFLAGS) $< -o $@

all : $(NAME)

bonus : $(BONUSOBJ)
		ar -rc $(NAME) $(BONUSOBJ)
		make -f ./libft/Makefile all bonus
		touch $@

clean :
		rm -rf $(OBJ) $(BONUSOBJ)
		make -f ./libft/Makefile clean

fclean :
		rm -rf $(OBJ) $(BONUSOBJ) $(NAME) bonus
		make -f ./libft/Makefile fclean

re : 
		make fclean all