/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:52:33 by sihong            #+#    #+#             */
/*   Updated: 2024/02/28 14:52:44 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	get_current_time(void)
{
	t_timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((int)(current_time.tv_sec * 1000000) + current_time.tv_usec);
}

int	get_time_from_start(int start_time)
{
	return ((get_current_time() - start_time) / 1000);
}

void	check_end(t_philo_stat *ps)
{
	int	i;

	sem_wait(ps->philo_info->mutex);
	i = 0;
	while (i < ps->philo_info->num_of_philo)
	{
		sem_post(ps->philo_info->end_checker[i]);
		i += 1;
	}
	sem_post(ps->philo_info->mutex);
}

void	check_termination(t_philo_stat *ps, int print_msg, char *s)
{
	sem_wait(ps->philo_info->mutex);
	if (ps->philo_info->termination == 1)
	{
		pthread_detach(ps->philo_info->pt);
		exit(0);
	}
	else if (print_msg)
		printf("%d %d %s\n", \
			get_time_from_start(ps->philo_info->start_time), ps->philo_num, s);
	sem_post(ps->philo_info->mutex);
}
