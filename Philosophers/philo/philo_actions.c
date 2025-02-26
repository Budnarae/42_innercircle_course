/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:05:13 by sihong            #+#    #+#             */
/*   Updated: 2024/02/26 12:05:16 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_sleep(t_philo_stat *ps, int last_meal_time)
{
	if (check_termination(ps, 1, "is sleeping") == 0)
		return (0);
	if (wait_for_cycle(ps, last_meal_time, ps->philo_info->time_to_sleep) == 0)
		return (0);
	return (1);
}

int	philo_think(t_philo_stat *ps, int last_meal_time)
{
	int	time_to_think;

	if (check_termination(ps, 1, "is thinking") == 0)
		return (0);
	time_to_think = \
		ps->philo_info->time_to_eat - ps->philo_info->time_to_sleep;
	if (time_to_think < 0)
		time_to_think = 0;
	if (wait_for_cycle(ps, last_meal_time, time_to_think) == 0)
		return (0);
	return (1);
}

int	philo_eat_2(int *left_fork, int *right_fork, \
		int *meal_ate, t_philo_stat *ps)
{
	*left_fork = ps->philo_info->forks[ps->philo_num];
	if (ps->philo_num + 1 == ps->philo_info->num_of_philo)
		*right_fork = ps->philo_info->forks[0];
	else
		*right_fork = ps->philo_info->forks[ps->philo_num + 1];
	if (check_termination(ps, 1, "is eating") == 0)
	{
		pthread_mutex_unlock(&ps->philo_info->mutex[*left_fork]);
		pthread_mutex_unlock(&ps->philo_info->mutex[*right_fork]);
		return (0);
	}
	*meal_ate += 1;
	if (ps->philo_info->must_eat > 0 && *meal_ate == ps->philo_info->must_eat)
	{
		pthread_mutex_lock \
			(&ps->philo_info->mutex[ps->philo_info->num_of_philo]);
		ps->philo_info->end_checker[ps->philo_num] = 1;
		pthread_mutex_unlock \
			(&ps->philo_info->mutex[ps->philo_info->num_of_philo]);
	}
	return (1);
}

int	philo_eat(t_philo_stat *ps, int *last_meal_time, int *meal_ate)
{
	int	left_fork;
	int	right_fork;

	if (philo_eat_2(&left_fork, &right_fork, meal_ate, ps) == 0)
		return (0);
	*last_meal_time = get_current_time();
	while ((get_current_time() - *last_meal_time) / 1000 \
			< ps->philo_info->time_to_eat)
	{
		if (sleep_check_death(ps, *last_meal_time) == 0)
		{
			pthread_mutex_unlock(&ps->philo_info->mutex[left_fork]);
			pthread_mutex_unlock(&ps->philo_info->mutex[right_fork]);
			return (0);
		}
	}
	pthread_mutex_unlock(&ps->philo_info->mutex[left_fork]);
	pthread_mutex_unlock(&ps->philo_info->mutex[right_fork]);
	return (1);
}

void	philo_hold_forks(t_philo_stat *ps)
{
	int	left_fork;
	int	right_fork;

	left_fork = ps->philo_info->forks[ps->philo_num];
	if (ps->philo_num + 1 == ps->philo_info->num_of_philo)
		right_fork = ps->philo_info->forks[0];
	else
		right_fork = ps->philo_info->forks[ps->philo_num + 1];
	pthread_mutex_lock(&ps->philo_info->mutex[left_fork]);
	if (check_termination(ps, 1, "has taken a fork") == 0)
		return ;
	pthread_mutex_lock(&ps->philo_info->mutex[right_fork]);
	if (check_termination(ps, 1, "has taken a fork") == 0)
		return ;
}
