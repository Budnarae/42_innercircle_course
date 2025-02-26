/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:51:17 by sihong            #+#    #+#             */
/*   Updated: 2024/02/26 13:51:28 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	sleep_check_death(t_philo_stat *ps, int last_meal_time)
{
	int	current_time;

	if (check_termination(ps, 0, 0) == 0)
		return (0);
	usleep(100);
	current_time = get_current_time();
	if ((current_time - last_meal_time) / 1000 >= ps->philo_info->time_to_die)
	{
		pthread_mutex_lock \
			(&ps->philo_info->mutex[ps->philo_info->num_of_philo]);
		if (ps->philo_info->termination == 0)
		{
			printf("%d %d died\n", \
			get_time_from_start(ps->philo_info->start_time), ps->philo_num);
			ps->philo_info->termination = 1;
		}
		pthread_mutex_unlock \
			(&ps->philo_info->mutex[ps->philo_info->num_of_philo]);
		return (0);
	}
	return (1);
}

int	check_end_dining(int *end_checker, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (end_checker[i] == 0)
			return (0);
		i += 1;
	}
	return (1);
}

int	check_termination(t_philo_stat *ps, int print_msg, char *s)
{
	pthread_mutex_lock(&ps->philo_info->mutex[ps->philo_info->num_of_philo]);
	if (ps->philo_info->termination != 0 \
		|| check_end_dining(ps->philo_info->end_checker, \
		ps->philo_info->num_of_philo) == 1)
	{
		pthread_mutex_unlock \
			(&ps->philo_info->mutex[ps->philo_info->num_of_philo]);
		return (0);
	}
	else if (print_msg)
		printf("%d %d %s\n", \
			get_time_from_start(ps->philo_info->start_time), ps->philo_num, s);
	pthread_mutex_unlock(&ps->philo_info->mutex[ps->philo_info->num_of_philo]);
	return (1);
}

int	wait_for_cycle(t_philo_stat *ps, int last_meal_time, int cycle)
{
	int	start;

	start = get_current_time();
	while ((get_current_time() - start) / 1000 \
			< cycle)
	{
		if (sleep_check_death(ps, last_meal_time) == 0)
			return (0);
	}
	return (1);
}
