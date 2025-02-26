/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:00:03 by sihong            #+#    #+#             */
/*   Updated: 2024/02/23 13:00:20 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo_stat	*ps;
	pthread_t		*pt;

	if (argc < 5 || argc > 6 || check_invalid_input(argc, argv) == 0)
	{
		printf("error : invalid input.\n");
		return (1);
	}
	if (ft_atoi(argv[1]) == 0)
	{
		printf("You need at least one philosophers.\n");
		return (1);
	}
	ps = alloc_philo_stat(argc, argv);
	if (ps == 0)
		return (1);
	pt = ft_calloc(ps[0].philo_info->num_of_philo, sizeof(pthread_t));
	if (pt == 0)
	{
		free_philo_stat(ps);
		return (1);
	}
	philosophers(pt, ps);
	return (0);
}
