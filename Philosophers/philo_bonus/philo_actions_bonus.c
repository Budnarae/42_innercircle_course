/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:05:13 by sihong            #+#    #+#             */
/*   Updated: 2024/02/26 12:05:16 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philo_sleep(t_philo_stat *ps, int last_meal_time)
{
	check_termination(ps, 1, "is sleeping");
	wait_for_cycle(ps, last_meal_time, ps->philo_info->time_to_sleep);
}

void	philo_think(t_philo_stat *ps, int last_meal_time)
{
	int	time_to_think;

	check_termination(ps, 1, "is thinking");
	time_to_think = \
		ps->philo_info->time_to_eat - ps->philo_info->time_to_sleep;
	if (time_to_think < 0)
		time_to_think = 0;
	wait_for_cycle(ps, last_meal_time, time_to_think);
}

void	philo_eat(t_philo_stat *ps, int *last_meal_time, int *meal_ate)
{
	check_termination(ps, 1, "is eating");
	*meal_ate += 1;
	if (ps->philo_info->must_eat > 0 && *meal_ate == ps->philo_info->must_eat)
	{
		check_end(ps);
	}
	*last_meal_time = get_current_time();
	wait_for_cycle(ps, *last_meal_time, ps->philo_info->time_to_eat);
	sem_post(ps->philo_info->forks);
	sem_post(ps->philo_info->forks);
}

void	philo_hold_forks(t_philo_stat *ps)
{
	sem_wait(ps->philo_info->forks);
	check_termination(ps, 1, "has taken a fork");
	sem_wait(ps->philo_info->forks);
	check_termination(ps, 1, "has taken a fork");
}
