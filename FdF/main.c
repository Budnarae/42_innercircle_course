/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:19:19 by sihong            #+#    #+#             */
/*   Updated: 2024/01/04 14:19:20 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_total	total;

	if (argc != 2)
		print_error_exit("error : you must input 1 filename.\n");
	parse_fdf(&total.vertex, argv[1], &total.map_size);
	back_up_vertex(&total);
	init_struct(&total.screen_size, &total.control);
	total.mlx_data.mlx_ptr = mlx_init();
	total.mlx_data.win_ptr
		= mlx_new_window(total.mlx_data.mlx_ptr, 2560, 1315, "fdf");
	total.viewpoint = ISO;
	draw_window(&total);
	mlx_key_hook(total.mlx_data.win_ptr, key_hook, &total);
	mlx_hook(total.mlx_data.win_ptr, 17, 1L << 2, end_fdf, &total.mlx_data);
	mlx_loop(total.mlx_data.mlx_ptr);
}
