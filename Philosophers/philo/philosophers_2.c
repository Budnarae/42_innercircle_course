/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:57:52 by sihong            #+#    #+#             */
/*   Updated: 2024/02/29 14:57:54 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_lonely_case(void *philo_stat)
{
	t_philo_stat	*ps;
	int				last_meal_time;

	ps = (t_philo_stat *)philo_stat;
	last_meal_time = ps->philo_info->start_time;
	pthread_mutex_lock \
		(&ps->philo_info->mutex[ps->philo_info->forks[ps->philo_num]]);
	printf("%d %d has taken a fork\n", \
			get_time_from_start(ps->philo_info->start_time), ps->philo_num);
	while ((get_current_time() - last_meal_time) / 1000 \
			< ps->philo_info->time_to_die)
	{
		if (sleep_check_death(ps, last_meal_time) == 0)
		{
			pthread_mutex_unlock \
				(&ps->philo_info->mutex[ps->philo_info->forks[ps->philo_num]]);
			return (0);
		}
	}
	return (0);
}

void	*philo_even_case(void *philo_stat)
{
	t_philo_stat	*ps;
	int				last_meal_time;
	int				meal_ate;

	ps = (t_philo_stat *)philo_stat;
	last_meal_time = ps->philo_info->start_time;
	if (ps->philo_num % 2 == 0)
		delay_start(ps, last_meal_time, ps->philo_info->time_to_eat);
	meal_ate = 0;
	while (1)
	{
		philo_hold_forks(ps);
		if (philo_eat(ps, &last_meal_time, &meal_ate) == 0)
			return (0);
		if (philo_sleep(ps, last_meal_time) == 0)
			return (0);
		if (philo_think(ps, last_meal_time) == 0)
			return (0);
	}
}

void	*philo_odd_sleepyhead_case(void *philo_stat)
{
	t_philo_stat	*ps;
	int				last_meal_time;
	int				meal_ate;

	ps = (t_philo_stat *)philo_stat;
	last_meal_time = ps->philo_info->start_time;
	if (ps->philo_num == ps->philo_info->num_of_philo - 1)
		delay_start(ps, last_meal_time, ps->philo_info->time_to_eat * 2);
	else if (ps->philo_num % 2 == 0)
		delay_start(ps, last_meal_time, ps->philo_info->time_to_eat);
	meal_ate = 0;
	while (1)
	{
		philo_hold_forks(ps);
		if (philo_eat(ps, &last_meal_time, &meal_ate) == 0)
			return (0);
		if (philo_sleep(ps, last_meal_time) == 0)
			return (0);
		if (philo_think(ps, last_meal_time) == 0)
			return (0);
	}
}

void	wait_for_timing(int i, int *turn, t_philo_stat *ps, int last_meal_time)
{
	if (i == *turn \
		&& *turn == (ps->philo_info->num_of_philo - ps->philo_num) / 2)
	{
		wait_for_cycle(ps, last_meal_time, \
			ps->philo_info->time_to_eat - (ps->philo_info->time_to_sleep - \
			ps->philo_info->time_to_eat) * *turn);
		*turn += ps->philo_info->num_of_philo / 2;
	}
	else if (i == *turn)
	{
		wait_for_cycle(ps, last_meal_time, \
			ps->philo_info->time_to_eat - \
			(ps->philo_info->time_to_sleep - ps->philo_info->time_to_eat) \
			* ps->philo_info->num_of_philo / 2);
		*turn += ps->philo_info->num_of_philo / 2;
	}
}

void	*philo_odd_normal_case(void *philo_stat)
{
	t_philo_stat	*ps;
	int				last_meal_time;
	int				meal_ate;
	int				turn;
	int				i;

	ps = (t_philo_stat *)philo_stat;
	last_meal_time = ps->philo_info->start_time;
	if (ps->philo_num % 2 == 0)
		delay_start(ps, last_meal_time, ps->philo_info->time_to_eat);
	meal_ate = 0;
	turn = (ps->philo_info->num_of_philo - ps->philo_num) / 2;
	i = 0;
	while (1)
	{
		wait_for_timing(i, &turn, ps, last_meal_time);
		philo_hold_forks(ps);
		if (philo_eat(ps, &last_meal_time, &meal_ate) == 0)
			return (0);
		if (philo_sleep(ps, last_meal_time) == 0)
			return (0);
		if (philo_think(ps, last_meal_time) == 0)
			return (0);
		i += 1;
	}
}
