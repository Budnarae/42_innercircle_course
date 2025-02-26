/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:00:03 by sihong            #+#    #+#             */
/*   Updated: 2024/02/23 13:00:20 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_philo_stat	*ps;
	pid_t			*pid;

	if (argc < 5 || argc > 6 || check_invalid_input(argc, argv) == 0)
	{
		printf("error : invalid input.\n");
		return (1);
	}
	ps = alloc_philo_stat(argc, argv);
	pid = ft_calloc(ps->philo_info->num_of_philo, sizeof(pid_t));
	philosophers(pid, ps);
	return (0);
}
