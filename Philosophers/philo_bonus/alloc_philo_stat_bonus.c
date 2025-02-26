/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_philo_stat_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:23:01 by sihong            #+#    #+#             */
/*   Updated: 2024/02/23 20:23:14 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	alloc_semaphore(t_philo_info *philo_info)
{
	int				i;
	char			*s;

	unlink_all_semaphore(philo_info);
	philo_info->forks = sem_open_adv("/forks", \
		O_CREAT, 0, philo_info->num_of_philo);
	philo_info->end_checker = \
		ft_calloc(philo_info->num_of_philo, sizeof(sem_t *));
	i = -1;
	while (++i < philo_info->num_of_philo)
	{
		s = ft_itoa(i);
		philo_info->end_checker[i] = sem_open_adv(s, \
			O_CREAT, 0, 0);
		free(s);
	}
	philo_info->mutex = sem_open_adv("/mutex", \
		O_CREAT, 0, 1);
}

t_philo_info	*alloc_philo_info(int argc, char **argv)
{
	t_philo_info	*philo_info;

	philo_info = ft_calloc(1, sizeof(t_philo_info));
	philo_info->num_of_philo = ft_atoi(argv[1]);
	if (philo_info->num_of_philo == 0)
	{
		printf("You need at least one philosophers.\n");
		exit(1);
	}
	philo_info->time_to_die = ft_atoi(argv[2]);
	philo_info->time_to_eat = ft_atoi(argv[3]);
	philo_info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo_info->must_eat = ft_atoi(argv[5]);
	else
		philo_info->must_eat = -1;
	alloc_semaphore(philo_info);
	return (philo_info);
}

t_philo_stat	*alloc_philo_stat(int argc, char **argv)
{
	t_philo_stat	*philo_stat;
	t_philo_info	*philo_info;
	int				i;

	philo_info = alloc_philo_info(argc, argv);
	philo_stat = \
		ft_calloc(philo_info->num_of_philo, sizeof(t_philo_stat));
	i = 0;
	while (i < philo_info->num_of_philo)
	{
		philo_stat[i].philo_num = i;
		philo_stat[i].philo_info = philo_info;
		i += 1;
	}
	return (philo_stat);
}
