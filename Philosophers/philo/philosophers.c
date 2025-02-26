/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:56:20 by sihong            #+#    #+#             */
/*   Updated: 2024/02/26 13:56:33 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wait_for_gap(int i, int *turn, t_philo_stat *ps, int last_meal_time)
{
	if (i == *turn)
	{
		wait_for_cycle(ps, last_meal_time, ps->philo_info->time_to_eat);
		*turn += ps->philo_info->num_of_philo / 2;
	}
}

void	*philo_odd_insomnia_case(void *philo_stat)
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
		wait_for_gap(i, &turn, ps, last_meal_time);
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

void	philo_odd_cases(pthread_t *pt, t_philo_stat *ps)
{
	int	i;

	i = -1;
	if (ps[0].philo_info->num_of_philo == 1)
		pthread_create(&pt[0], NULL, &philo_lonely_case, &ps[0]);
	else if (ps[0].philo_info->num_of_philo % 2 == 1 \
		&& ps[0].philo_info->time_to_sleep >= ps[0].philo_info->time_to_eat * 2)
	{
		while (++i < ps[0].philo_info->num_of_philo)
			pthread_create(&pt[i], NULL, &philo_odd_sleepyhead_case, &ps[i]);
	}
	else if (ps[0].philo_info->num_of_philo % 2 == 1 \
		&& ps[0].philo_info->time_to_sleep > ps[0].philo_info->time_to_eat)
	{
		while (++i < ps[0].philo_info->num_of_philo)
			pthread_create(&pt[i], NULL, &philo_odd_normal_case, &ps[i]);
	}
	else if (ps[0].philo_info->num_of_philo % 2 == 1 \
		&& ps[0].philo_info->time_to_sleep <= ps[0].philo_info->time_to_eat)
	{
		while (++i < ps[0].philo_info->num_of_philo)
			pthread_create(&pt[i], NULL, &philo_odd_insomnia_case, &ps[i]);
	}
}

void	philosophers(pthread_t *pt, t_philo_stat *ps)
{
	int	i;

	i = -1;
	ps->philo_info->start_time = get_current_time();
	if (ps[0].philo_info->must_eat == 0)
	{
		printf("philosophers don't have to eat!\n");
		free(pt);
		free_philo_stat(ps);
		return ;
	}
	if (ps[0].philo_info->num_of_philo % 2 == 0)
	{
		while (++i < ps[0].philo_info->num_of_philo)
			pthread_create(&pt[i], NULL, &philo_even_case, &ps[i]);
	}
	philo_odd_cases(pt, ps);
	i = -1;
	while (++i < ps[0].philo_info->num_of_philo)
		pthread_join(pt[i], NULL);
	free(pt);
	free_philo_stat(ps);
}
