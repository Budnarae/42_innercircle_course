/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:54:26 by chansjeo          #+#    #+#             */
/*   Updated: 2024/06/29 19:57:06 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

static int	exit_hook(void)
{
	exit(0);
}

static int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

static void	init_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		exit(1);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "miniRT");
	if (vars->win == NULL)
		exit(1);
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (vars->img == NULL)
		exit(1);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, \
			&vars->line_length, &vars->endian);
	if (vars->addr == NULL)
		exit(1);
}

void	free_factor(t_factor *f)
{
	free(f->amb);
	free(f->cam);
	free(f->light);
	free(f->cy);
	free(f->pl);
	free(f->sp);
	free(f);
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_factor	*f;

	if (argc != 2)
		ft_error_msg("usage: ./miniRT [filename].rt\n", 1);
	f = get_factor(argv[1]);
	init_window(&vars);
	renderer(&vars, f);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.mlx);
	free_factor(f);
	return (0);
}
