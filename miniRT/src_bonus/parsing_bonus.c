/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:44:29 by chansjeo          #+#    #+#             */
/*   Updated: 2024/07/02 13:36:21 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/miniRT_bonus.h"

static void	free_in_gnl(char *line, char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
	free(line);
}

t_factor	*input_info(t_factor *f, int fd, char *line, char **args)
{
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		args = ft_split_adv(line);
		if (ft_strncmp(args[0], "A", 2) == 0)
			get_amb(f->amb++, args);
		else if (ft_strncmp(args[0], "C", 2) == 0)
			get_cam(f->cam++, args);
		else if (ft_strncmp(args[0], "L", 2) == 0)
			get_light(f->light++, args);
		else if (ft_strncmp(args[0], "pl", 3) == 0)
			get_pl(f->pl++, args);
		else if (ft_strncmp(args[0], "sp", 3) == 0)
			get_sp(f->sp++, args);
		else if (ft_strncmp(args[0], "cy", 3) == 0)
			get_cy(f->cy++, args);
		else if (ft_strncmp(args[0], "co", 3) == 0)
			get_co(f->co++, args);
		else if (!is_space(args[0]))
			ft_error_msg("Invalid factor exist!\n", 1);
		free_in_gnl(line, args);
	}
	return (f);
}

void	make_factor_tab(t_factor *f, int fd, char *line, char **args)
{
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		args = ft_split_adv(line);
		if (ft_strncmp(args[0], "A", 2) == 0)
			f->tab[0]++;
		else if (ft_strncmp(args[0], "C", 2) == 0)
			f->tab[1]++;
		else if (ft_strncmp(args[0], "L", 2) == 0)
			f->tab[2]++;
		else if (ft_strncmp(args[0], "pl", 3) == 0)
			f->tab[3]++;
		else if (ft_strncmp(args[0], "sp", 3) == 0)
			f->tab[4]++;
		else if (ft_strncmp(args[0], "cy", 3) == 0)
			f->tab[5]++;
		else if (ft_strncmp(args[0], "co", 3) == 0)
			f->tab[6]++;
		else if (!is_space(args[0]))
			ft_error_msg("Invalid factor exist!\n", 1);
		free_in_gnl(line, args);
	}
}

void	alloc_factor(t_factor *factor)
{
	factor->amb = ft_calloc_adv(factor->tab[0], sizeof(t_ambient));
	factor->cam = ft_calloc_adv(factor->tab[1], sizeof(t_camera));
	factor->light = ft_calloc_adv(factor->tab[2], sizeof(t_light));
	factor->pl = ft_calloc_adv(factor->tab[3], sizeof(t_plane));
	factor->sp = ft_calloc_adv(factor->tab[4], sizeof(t_sphere));
	factor->cy = ft_calloc_adv(factor->tab[5], sizeof(t_cylinder));
	factor->co = ft_calloc_adv(factor->tab[6], sizeof(t_cone));
}

t_factor	*get_factor(const char *path)
{
	t_factor	*factor;
	int			fd;
	char		*line;
	char		**args;

	line = 0;
	args = 0;
	check_filename(path);
	fd = open_read_only(path);
	factor = ft_calloc_adv(1, sizeof(t_factor));
	make_factor_tab(factor, fd, line, args);
	if (factor->tab[0] != 1 || factor->tab[1] != 1 || factor->tab[2] < 1)
		ft_error_msg("Factors must have only one factor.\n", 1);
	alloc_factor(factor);
	close(fd);
	fd = open_read_only(path);
	factor = input_info(factor, fd, line, args);
	reset_factor(factor);
	close(fd);
	return (factor);
}
