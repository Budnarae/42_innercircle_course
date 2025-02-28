SRC = src/main.c src/env_list.c src/env_list_2.c src/builtin.c src/builtin_2.c src/is_valid.c\
        src/run_command.c src/run_command_2.c src/run_command_utils.c\
        src/run_command_utils_2.c src/operator.c src/here_doc.c src/here_doc_2.c src/cmd_check.c\
        src/cmd_check_2.c src/signal_handler.c src/utils.c src/utils_2.c src/utils_3.c src/free_struct.c \
        src/seperate_quote.c src/seperate_others.c src/seperate_others_2.c src/paren_stack.c \
        src/check_syntax_error.c src/expanse_wild_card.c src/expanse_wild_card_2.c src/expanse_wild_card_3.c \
        src/expanse_wild_card_4.c src/reorganize_args.c src/reorganize_args_2.c src/make_basic_parse_tree.c \
        src/make_basic_parse_tree_2.c src/make_complete_parse_tree.c src/parse_line.c \
        src/parse_for_expanse.c src/parse_for_expanse_2.c src/parse_for_expanse_3.c \
        src/parse_for_expanse_4.c src/parse_for_expanse_5.c src/parse_for_expanse_6.c
OBJ = $(SRC:.c=.o)
BONUS_SRC = bonus_src/main_bonus.c bonus_src/env_list_bonus.c bonus_src/env_list_2_bonus.c bonus_src/builtin_bonus.c bonus_src/builtin_2_bonus.c bonus_src/is_valid_bonus.c\
    	bonus_src/run_command_bonus.c bonus_src/run_command_2_bonus.c bonus_src/run_command_utils_bonus.c\
        bonus_src/run_command_utils_2_bonus.c bonus_src/operator_bonus.c bonus_src/here_doc_bonus.c bonus_src/here_doc_2_bonus.c bonus_src/cmd_check_bonus.c\
        bonus_src/cmd_check_2_bonus.c bonus_src/signal_handler_bonus.c bonus_src/utils_bonus.c bonus_src/utils_2_bonus.c bonus_src/utils_3_bonus.c bonus_src/free_struct_bonus.c \
        bonus_src/seperate_quote_bonus.c bonus_src/seperate_others_bonus.c bonus_src/seperate_others_2_bonus.c bonus_src/paren_stack_bonus.c \
        bonus_src/check_syntax_error_bonus.c bonus_src/expanse_wild_card_bonus.c bonus_src/expanse_wild_card_2_bonus.c bonus_src/expanse_wild_card_3_bonus.c \
        bonus_src/expanse_wild_card_4_bonus.c bonus_src/reorganize_args_bonus.c bonus_src/reorganize_args_2_bonus.c bonus_src/make_basic_parse_tree_bonus.c \
        bonus_src/make_basic_parse_tree_2_bonus.c bonus_src/make_complete_parse_tree_bonus.c bonus_src/parse_line_bonus.c \
        bonus_src/parse_for_expanse_bonus.c bonus_src/parse_for_expanse_2_bonus.c bonus_src/parse_for_expanse_3_bonus.c \
        bonus_src/parse_for_expanse_4_bonus.c bonus_src/parse_for_expanse_5_bonus.c bonus_src/parse_for_expanse_6_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

CC = cc
CFLAGS = -Wextra -Wall -Werror -g
LIBFTFLAGS = -Llibft/ -lft
READLINEFLAGS = -lreadline

NAME = minishell

$(NAME) : $(OBJ)
		make -sC ./libft/ all bonus
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFTFLAGS) $(READLINEFLAGS)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

bonus : $(BONUS_OBJ)
		make -sC ./libft/ all bonus
		$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJ) $(LIBFTFLAGS) $(READLINEFLAGS)
		touch $@

clean :
		rm -rf $(OBJ) $(BONUS_OBJ)
		make -sC ./libft/ clean

fclean :
		rm -rf $(OBJ) $(BONUS_OBJ) $(NAME) bonus
		make -sC ./libft/ fclean

re : 
		make fclean all