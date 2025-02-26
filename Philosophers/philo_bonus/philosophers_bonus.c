/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:53:54 by sihong            #+#    #+#             */
/*   Updated: 2024/02/28 15:54:13 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philo_odd_normal_case(t_philo_stat *ps)
{
	int				last_meal_time;
	int				meal_ate;
	int				turn;
	int				i;

	syncronize_start_time(ps);
	pthread_create(&ps->philo_info->pt, NULL, &check_end_dining, ps);
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
		philo_eat(ps, &last_meal_time, &meal_ate);
		philo_sleep(ps, last_meal_time);
		philo_think(ps, last_meal_time);
		i += 1;
	}
}

void	*philo_odd_insomnia_case(t_philo_stat *ps)
{
	int				last_meal_time;
	int				meal_ate;
	int				turn;
	int				i;

	syncronize_start_time(ps);
	pthread_create(&ps->philo_info->pt, NULL, &check_end_dining, ps);
	last_meal_time = ps->philo_info->start_time;
	if (ps->philo_num % 2 == 0)
		delay_start(ps, last_meal_time, ps->philo_info->time_to_eat);
	meal_ate = 0;
	turn = (ps->philo_info->num_of_philo - ps->philo_num) / 2;
	i = -1;
	while (1)
	{
		if (++i == turn)
		{
			wait_for_cycle(ps, last_meal_time, ps->philo_info->time_to_eat);
			turn += ps->philo_info->num_of_philo / 2;
		}
		philo_hold_forks(ps);
		philo_eat(ps, &last_meal_time, &meal_ate);
		philo_sleep(ps, last_meal_time);
		philo_think(ps, last_meal_time);
	}
}

void	zombie_collecter(pid_t *pid, t_philo_stat *ps)
{
	int	i;
	int	pid_tmp;
	int	wstatus;

	pid_tmp = waitpid_adv(-1, &wstatus, 0);
	i = -1;
	while (++i < ps->philo_info->num_of_philo)
	{
		if (pid[i] == pid_tmp)
			continue ;
		kill(pid[i], SIGKILL);
	}
	i = -1;
	while (++i < ps->philo_info->num_of_philo - 1)
		waitpid_adv(-1, &wstatus, 0);
}

void	child_part(int i, t_philo_stat *ps)
{
	if (ps[0].philo_info->num_of_philo % 2 == 0)
		philo_even_case(&ps[i]);
	else if (ps[0].philo_info->num_of_philo == 1)
		philo_lonely_case(&ps[0]);
	else if (ps[0].philo_info->num_of_philo % 2 == 1 \
		&& ps[0].philo_info->time_to_sleep \
		>= ps[0].philo_info->time_to_eat * 2)
		philo_odd_sleepyhead_case(&ps[i]);
	else if (ps[0].philo_info->num_of_philo % 2 == 1 \
		&& ps[0].philo_info->time_to_sleep \
		> ps[0].philo_info->time_to_eat)
		philo_odd_normal_case(&ps[i]);
	else if (ps[0].philo_info->num_of_philo % 2 == 1 \
		&& ps[0].philo_info->time_to_sleep \
		<= ps[0].philo_info->time_to_eat)
		philo_odd_insomnia_case(&ps[i]);
}

void	philosophers(pid_t *pid, t_philo_stat *ps)
{
	int	i;

	if (ps[0].philo_info->must_eat == 0)
	{
		printf("philosophers don't have to eat!\n");
		free(pid);
		free_philo_stat(ps);
		return ;
	}
	i = -1;
	ps->philo_info->start_time = get_current_time();
	while (++i < ps->philo_info->num_of_philo)
	{
		pid[i] = fork_adv();
		if (pid[i] == 0)
			child_part(i, ps);
	}
	zombie_collecter(pid, ps);
	free(pid);
	free_philo_stat(ps);
}
