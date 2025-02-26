/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_philo_stat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:23:01 by sihong            #+#    #+#             */
/*   Updated: 2024/02/23 20:23:14 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	*alloc_mutexs(int philo_num)
{
	int				i;
	int				j;
	pthread_mutex_t	*mutex;

	mutex = ft_calloc(philo_num + 1, sizeof(pthread_mutex_t));
	if (mutex == 0)
		return (0);
	i = 0;
	while (i < philo_num + 1)
	{
		if (pthread_mutex_init(&mutex[i], NULL) != 0)
		{
			j = 0;
			while (j < i)
			{
				pthread_mutex_destroy(&mutex[j]);
				j += 1;
			}
			free(mutex);
			return (0);
		}
		i += 1;
	}
	return (mutex);
}

int	alloc_forks_checker(t_philo_info *philo_info)
{
	int	i;

	philo_info->forks = \
		ft_calloc(philo_info->num_of_philo, sizeof(int));
	if (philo_info->forks == 0)
	{
		free_philo_info(philo_info);
		return (0);
	}
	i = 0;
	while (i < philo_info->num_of_philo)
	{
		philo_info->forks[i] = i;
		i += 1;
	}
	philo_info->end_checker = \
		ft_calloc(philo_info->num_of_philo, sizeof(int));
	if (philo_info->end_checker == 0)
	{
		free_philo_info(philo_info);
		return (0);
	}
	philo_info->end_checker = memset(philo_info->end_checker, \
		0, philo_info->num_of_philo * sizeof(int));
	return (1);
}

t_philo_info	*alloc_philo_info(int argc, char **argv)
{
	t_philo_info	*philo_info;

	philo_info = ft_calloc(1, sizeof(t_philo_info));
	if (philo_info == 0)
		return (0);
	philo_info->num_of_philo = ft_atoi(argv[1]);
	philo_info->time_to_die = ft_atoi(argv[2]);
	philo_info->time_to_eat = ft_atoi(argv[3]);
	philo_info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo_info->must_eat = ft_atoi(argv[5]);
	else
		philo_info->must_eat = -1;
	if (alloc_forks_checker(philo_info) == 0)
		return (0);
	philo_info->mutex = alloc_mutexs(philo_info->num_of_philo);
	if (philo_info->mutex == 0)
	{
		free_philo_info(philo_info);
		return (0);
	}
	return (philo_info);
}

t_philo_stat	*alloc_philo_stat(int argc, char **argv)
{
	t_philo_stat	*philo_stat;
	t_philo_info	*philo_info;
	int				i;

	philo_info = alloc_philo_info(argc, argv);
	if (philo_info == 0)
		return (0);
	philo_info->termination = 0;
	philo_stat = \
		ft_calloc(philo_info->num_of_philo, sizeof(t_philo_stat));
	if (philo_stat == 0)
	{
		free_philo_info(philo_info);
		return (0);
	}
	i = 0;
	while (i < philo_info->num_of_philo)
	{
		philo_stat[i].philo_num = i;
		philo_stat[i].philo_info = philo_info;
		i += 1;
	}
	return (philo_stat);
}
