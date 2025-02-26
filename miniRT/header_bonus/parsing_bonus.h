/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:30:01 by chansjeo          #+#    #+#             */
/*   Updated: 2024/07/02 13:35:33 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

# include "factor_bonus.h"

# define COLOR 10
# define UNIT_VEC 11

void		ft_error_msg(char *str, int exit_status);
double		ft_atof(char *str);
t_factor	*get_factor(const char *path);
void		reset_factor(t_factor *f);
t_factor	*input_info(t_factor *factor, int fd, \
						char *line, char **args);
void		alloc_factor(t_factor *factor);
int			is_space(const char *str);
char		*ft_strsep(char **s, const char *ct);
int			check_filename(const char *path);
int			open_read_only(const char *path);
void		get_three_pos(t_vec3 *v, char *arg, int type);
void		get_amb(t_ambient *amb, char **args);
void		get_cam(t_camera *cam, char **args);
void		get_light(t_light *light, char **args);
void		get_pl(t_plane *pl, char **args);
void		get_sp(t_sphere *sp, char **args);
void		get_cy(t_cylinder *cy, char **args);
void		get_co(t_cone *co, char **args);

#endif
