/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:06:46 by sihong            #+#    #+#             */
/*   Updated: 2024/03/01 18:06:58 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*check_end_dining(void *philo_stat)
{
	t_philo_stat	*ps;
	int				i;

	ps = (t_philo_stat *)philo_stat;
	i = 0;
	while (i < ps->philo_info->num_of_philo)
	{
		sem_wait(ps->philo_info->end_checker[ps->philo_num]);
		i += 1;
	}
	sem_wait(ps->philo_info->mutex);
	ps->philo_info->termination = 1;
	sem_post(ps->philo_info->mutex);
	return (0);
}

void	philo_lonely_case(t_philo_stat *ps)
{
	int			last_meal_time;

	last_meal_time = ps->philo_info->start_time;
	sem_wait(ps->philo_info->forks);
	printf("%d %d has taken a fork\n", \
			get_time_from_start(ps->philo_info->start_time), ps->philo_num);
	wait_for_cycle(ps, last_meal_time, ps->philo_info->time_to_die);
}

void	philo_even_case(t_philo_stat *ps)
{
	int				last_meal_time;
	int				meal_ate;

	syncronize_start_time(ps);
	pthread_create(&ps->philo_info->pt, NULL, &check_end_dining, ps);
	last_meal_time = ps->philo_info->start_time;
	if (ps->philo_num % 2 == 0)
		delay_start(ps, last_meal_time, ps->philo_info->time_to_eat);
	meal_ate = 0;
	while (1)
	{
		philo_hold_forks(ps);
		philo_eat(ps, &last_meal_time, &meal_ate);
		philo_sleep(ps, last_meal_time);
		philo_think(ps, last_meal_time);
	}
}

void	philo_odd_sleepyhead_case(t_philo_stat *ps)
{
	int				last_meal_time;
	int				meal_ate;

	syncronize_start_time(ps);
	pthread_create(&ps->philo_info->pt, NULL, &check_end_dining, ps);
	last_meal_time = ps->philo_info->start_time;
	if (ps->philo_num == ps->philo_info->num_of_philo - 1)
		delay_start(ps, last_meal_time, ps->philo_info->time_to_eat * 2);
	else if (ps->philo_num % 2 == 0)
		delay_start(ps, last_meal_time, ps->philo_info->time_to_eat);
	meal_ate = 0;
	while (1)
	{
		philo_hold_forks(ps);
		philo_eat(ps, &last_meal_time, &meal_ate);
		philo_sleep(ps, last_meal_time);
		philo_think(ps, last_meal_time);
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
