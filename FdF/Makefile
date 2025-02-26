SRC = main.c utils.c parse_fdf.c parse_fdf_2.c init_matrix.c init_matrix_2.c init_matrix_3.c control_vertex.c draw_window.c bresenham.c bresenham_2.c hook.c
OBJ = $(SRC:.c=.o)
BONUS_SRC = main_bonus.c utils_bonus.c parse_fdf_bonus.c parse_fdf_2_bonus.c init_matrix_bonus.c init_matrix_2_bonus.c init_matrix_3_bonus.c control_vertex_bonus.c draw_window_bonus.c bresenham_bonus.c bresenham_2_bonus.c hook.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

CC = cc
CFLAGS = -Wextra -Wall -Werror -g
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
LIBFTFLAGS = -Llibft/ -lft

NAME = fdf

$(NAME) : $(OBJ)
		make -C ./libft/ all bonus
		$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFTFLAGS) -g -o $(NAME) $(OBJ) 

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

bonus : $(BONUS_OBJ)
		make -C ./libft/ all bonus
		$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFTFLAGS) -g -o $(NAME) $(BONUS_OBJ)
		touch $@

clean :
		rm -rf $(OBJ) $(BONUS_OBJ)
		make -C ./libft/ clean

fclean :
		rm -rf $(OBJ) $(BONUS_OBJ) $(NAME) bonus
		make -C ./libft/ fclean

re : 
		make fclean all