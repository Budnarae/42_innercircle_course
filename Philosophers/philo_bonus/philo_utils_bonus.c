/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:51:17 by sihong            #+#    #+#             */
/*   Updated: 2024/02/26 13:51:28 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	sleep_check_death(t_philo_stat *ps, int last_meal_time)
{
	int	current_time;

	usleep(100);
	current_time = get_current_time();
	if ((current_time - last_meal_time) / 1000 >= ps->philo_info->time_to_die)
	{
		sem_wait(ps->philo_info->mutex);
		pthread_detach(ps->philo_info->pt);
		printf("%d %d died\n", \
			get_time_from_start(ps->philo_info->start_time), ps->philo_num);
		exit(0);
	}
}

void	wait_for_cycle(t_philo_stat *ps, int last_meal_time, int cycle)
{
	int	start;

	start = get_current_time();
	while ((get_current_time() - start) / 1000 \
			< cycle)
		sleep_check_death(ps, last_meal_time);
}
