/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:56:30 by chansjeo          #+#    #+#             */
/*   Updated: 2024/07/02 15:28:28 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <pthread.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "vector_bonus.h"
# include "parsing_bonus.h"
# include "factor_bonus.h"

/* image.h */

# define WIDTH 1300
# define HEIGHT 1300
# define TEX_SIZE 64
# define ESC 53

typedef struct s_img_tool	t_img_tool;

typedef struct s_tex
{
	int		tex_width;
	int		tex_height;
	char	*tex_addr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*tex_img;
}	t_tex;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_img_tool	*img_tool;
	t_tex		tex;
	t_tex		map;
}	t_vars;

typedef struct s_img_tool
{
	int		img_width;
	int		img_height;
	double	viewport_height;
	double	viewport_width;	
}	t_img_tool;

typedef struct s_dic
{
	double	a;
	double	b;
	double	c;
	double	dic;
	double	t_pos;
	double	t_neg;
}	t_dic;

typedef struct s_phong
{
	t_vec3	obj_color;
	t_vec3	ambient;
	t_vec3	diffuse;
	t_vec3	specular;
}	t_phong;

typedef struct s_thread_data
{
	int			start_x;
	int			end_x;
	int			start_y;
	int			end_y;
	t_vec3		up_left_pixel;
	t_vars		*vars;
	t_factor	*f;
}	t_thread_data;

typedef struct s_thread_tool
{
	int			num_threads;
	int			section_width;
	int			section_height;
	int			cols;
	t_vars		*vars;
	t_factor	*f;
	t_vec3		up_left_pixel;
}	t_thread_tool;

//color.c
int			create_rgb(t_vec3 color);
int			create_unit_rgb(t_vec3 color);
t_vec3		clip_color(t_vec3 color);
void		my_mlx_pixel_put(t_vars *data, int x, int y, int color);

void		*ft_calloc_adv(size_t count, size_t size);
char		**ft_split_adv(char *str);
//color_2.c
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);

//sihong

//relocate_to_view_space.c
t_vec3		relocate_vertex_to_view_space(t_vec3 v3, t_mat4x4 view);
void		relocate_lights_to_view_space(int lit_num, t_light *light, \
			t_mat4x4 view);
void		relocate_planes_to_view_space(int pl_num, t_plane *pl, \
			t_mat4x4 view);
void		relocate_spheres_to_view_space(int sp_num, t_sphere *sp, \
			t_mat4x4 view);
void		relocate_cylinders_to_view_space(int sy_num, t_cylinder *cy, \
			t_mat4x4 view);
//relocate_to_view_space_2.c
void		relocate_cones_to_view_space(int co_num, t_cone *co, \
			t_mat4x4 view);
//get_view_matrix.c
t_vec3		*get_camera_local_axis(t_camera *cam);
t_mat4x4	get_view_matrix(t_camera *cam);
//check_col_all_sp.c
t_dic		get_sp_dic(t_vec3 ray_to_pixel, t_sphere sp);
t_col_info	check_col_1sp(t_vec3 ray_to_pixel, t_sphere sp);
t_vec3		get_checker_ball_2(double height, double diameter, \
			t_vec3 color_a, t_vec3 color_b);
t_vec3		get_checker_ball(t_col_info col_pos, t_sphere sp);
t_col_info	check_col_all_sp(t_vec3 ray_to_pixel, int sp_num, t_sphere *sp);
//get_cy_matrix.c
t_vec3		*get_fi_xyz_local(t_vec3 unit_vec);
t_mat4x4	get_rev_fi_matrix(t_vec3 center_pos, t_vec3 unit_vec);
t_mat4x4	get_fi_matrix(t_vec3 center_pos, t_vec3 unit_vec);
//check_col_cy_side.c
t_dic		get_cy_side_dic(t_vec4 cam_pos, t_vec4 pl_pos, double diameter);
t_col_info	check_cy_height(t_vec4 cam_pos, t_vec4 pl_pos, t_cylinder cy, \
			double t);
t_col_info	restore_to_origin(t_mat4x4 restore, t_col_info col);
t_col_info	check_col_cy_side(t_vec4 cam_pos, t_vec4 pl_pos, t_cylinder cy);
//check_col_all_cy.c
t_col_info	get_col_cy_cap(int sign, t_vec4 cam_pos, t_vec4 pl_pos, \
			t_cylinder cy);
t_col_info	check_col_cy_cap(t_vec4 cam_pos, t_vec4 pl_pos, t_cylinder cy);
t_col_info	check_col_all_cy(t_vec3 ray_to_pixel, int cy_num, t_cylinder *cy);
//check_col_all_pl.c
t_col_info	check_col_1pl(t_vec3 ray_to_pixel, t_plane pl);
t_col_info	check_col_all_pl(t_vec3 ray_to_pixel, int pl_num, \
			t_plane *pl, t_vars *vars);
//get_texture_plane.c
t_col_info	get_texture_info(t_vec3 v, t_vars *vars);
t_col_info	get_texture_plane(t_col_info col, t_plane pl, t_vars *vars);
//check_col_all_co.c
t_col_info	get_col_co_cap(t_vec4 cam_pos, t_vec4 pl_pos, \
			t_cone co);
t_col_info	check_col_co_cap(t_vec4 cam_pos, t_vec4 pl_pos, t_cone co);
t_col_info	check_col_all_co(t_vec3 ray_to_pixel, int co_num, t_cone *co);
//check_col_all_co_2.c
t_dic		get_co_side_dic(t_vec3 c, t_vec3 p, t_cone co);
t_col_info	get_co_side_col(double t, double h, t_vec3 cam_pos, t_vec3 pl_pos);
t_col_info	check_col_co_side_2(t_cone co, t_dic dic, \
			t_vec3 cam_pos, t_vec3 pl_pos);
t_col_info	check_col_co_side(t_vec3 cam_pos, t_vec3 pl_pos, t_cone co);
//check_lit_col_all_sp.c
t_dic		get_lit_sp_dic(t_vec3 col_pos, t_vec3 lit_pos, t_sphere sp);
int			check_lit_col_all_sp(int lit_num, t_vec3 col_pos, t_factor *f);
//check_lit_col_all_cy.c
t_dic		get_lit_cy_side(t_vec3 col_pos, t_vec3 lit_pos, double diameter);
int			check_lit_col_cy_side(t_vec3 col_pos, t_vec3 lit_pos, \
			t_cylinder cy);
int			check_lit_col_cy_cap(t_vec3 col_pos, t_vec3 lit_pos, t_cylinder cy);
int			check_lit_col_all_cy(int lit_num, t_vec3 col_pos, t_factor *f);
//check_lit_col_all_pl.c
int			check_lit_col_all_pl(int lit_num, t_vec3 col_pos, t_factor *f);
//check_lit_col_all_co.c
int			check_lit_col_co_side(t_vec3 col_pos, t_vec3 lit_pos, t_cone co);
int			check_lit_col_co_cap(t_vec3 col_pos, t_vec3 lit_pos, t_cone co);
int			check_lit_col_all_co(int lit_num, t_vec3 col_pos, t_factor *f);
//get_pixel_color.c
void		calculate_multiple_light(t_phong *phong, \
			t_col_info col, t_factor *f);
t_vec3		get_pixel_color(t_col_info col, t_factor *f);
//raytracer.c
t_col_info	get_collision_location(t_vec3 ray_to_pixel, \
			t_factor *f, t_vars *vars);
int			check_light_collision(int lit_num, t_vec3 col_pos, t_factor *f);
t_vec3		shoot_ray_to_pixel(t_vec3 ray_to_pixel, t_factor *f, t_vars *vars);
void		raytracer(t_vars *vars, t_factor *f);
//renderer.c
void		black_screen(t_vars *vars);
void		translate_to_view_space(t_factor *f);
double		get_focal_length(double fov);
void		renderer(t_vars *vars, t_factor *f);
void		distribute_to_thread(int rows, int cols, t_vars *vars, t_factor *f);
//init_mlx.c
void		init_img(t_vars *vars);
void		init_window(t_vars *vars);
//main.c
int			exit_hook(void);
int			key_hook(int keycode, t_vars *vars);
void		free_factor(t_factor *f);

#endif
