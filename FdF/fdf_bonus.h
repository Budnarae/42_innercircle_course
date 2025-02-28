/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:19:47 by sihong            #+#    #+#             */
/*   Updated: 2024/01/04 14:19:49 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# define PI 3.141592
# define A 97
# define D 100
# define W 119
# define S 115
# define Q 113
# define E 101
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define I 105
# define J 106
# define K 107
# define L 108
# define U 117
# define O 111
# define SPACE 32
# define ISO 333
# define CAB 222


# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_vertex
{
	float	vertex[4];
	int		color[4];
}	t_vertex;

typedef struct s_map_size
{
	int	row_size;
	int	*col_size;
	int	biggest_col_size;
	int	biggest_z_size;
}	t_map_size;

typedef struct s_matrixs
{
	float	t_screen[4][4];
	float	r_isometric[4][4];
	float	r_cabinet[4][4];
	float	t[4][4];
	float	r[4][4];
	float	s[4][4];
	float	t_origin[4][4];
	float	merged_matrix[4][4];
}	t_matrixs;

typedef struct s_screan_size
{
	int	col;
	int	row;
}	t_screen_size;

typedef struct s_control
{
	float	scale_factor;
	float	x_pitch;
	float	y_roll;
	float	z_yaw;
	float	t_x;
	float	t_y;
	float	t_z;
}	t_control;

typedef struct s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img_data	img_data;
}	t_mlx_data;

typedef struct s_total
{
	t_vertex		**vertex;
	t_vertex		**vertex_back_up;
	t_screen_size	screen_size;
	t_map_size		map_size;
	t_control		control;
	t_matrixs		matrixs;
	t_mlx_data		mlx_data;
	int				viewpoint;
}	t_total;

//hook.c
void	key_hook_2(int keycode, t_total *total);
int		key_hook(int keycode, t_total *total);
//utils.c
void	define_color(float vertex[4], int color[4]);
int		end_fdf(t_mlx_data *mlx_data);
void	init_struct(t_screen_size *screen_size, t_control *control);
void	print_error_exit(const char *s);
void	check_file_format(char *file_name);
//parse_fdf.c
void	find_col_size_alloc(char ***splited_col, char *col,
			t_vertex ***vertex, int row_size);
int		input_data_to_col(char **splited_col, t_vertex ***vertex,
			int row_size);
void	malloc_vertex_col(t_vertex ***vertex, char *file_name,
			t_map_size *map_size);
int		malloc_vertex_row(t_vertex ***vertex, char *file_name);
void	parse_fdf(t_vertex ***vertex, char *file_name, t_map_size *map_size);
//parse_fdf_2.c
void	find_biggest_col_z_size(t_map_size *map_size, int row_size,
			t_vertex ***vertex);
//init_matrix.c
void	init_r(float m[4][4], t_control c);
void	init_s(float m[4][4], t_control control);
void	init_t_origin(float m[4][4], t_map_size ms);
void	init_merged_matrix(float m[4][4]);
void	init_matrix(t_total *total);
//init_matric_2.c
void	init_t_screen(float m[4][4], t_screen_size screen_size);
void	init_r_isometric(float m[4][4]);
void	init_t(float m[4][4], t_control c);
void	matrix_multiplication_4x4_4x4(float m1[4][4], float m2[4][4]);
void	matrix_multiplication_4x4_1x4(float m1[4][4], float m2[4]);
//init_matric_3.c
void	init_r_cabinet(float m[4][4]);
//relocate_vertex.c
void	roll_back_vertex(t_total *total);
void	back_up_vertex(t_total *total);
void	relocate_vertex(t_vertex **vertex, float m[4][4],
			t_map_size map_size);
//draw_window.c
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void	my_mlx_vertex_put(t_vertex **vertex, t_map_size map_size,
			t_mlx_data mlx_data);
void	draw_window(t_total *total);
//bresenham.c
void	quadrant_4(t_mlx_data mlx_data, t_vertex a, t_vertex b);
void	quadrant_3(t_mlx_data mlx_data, t_vertex a, t_vertex b);
void	quadrant_2(t_mlx_data mlx_data, t_vertex a, t_vertex b);
void	quadrant_1(t_mlx_data mlx_data, t_vertex a, t_vertex b);
void	bresenham(t_mlx_data mlx_data, t_vertex a, t_vertex b);
//bresenham_2.c
int		color_lerp(int color_a[4], int color_b[4], float n, float range);
void	bresenham_2(t_mlx_data mlx_data, t_vertex a, t_vertex b);

#endif
