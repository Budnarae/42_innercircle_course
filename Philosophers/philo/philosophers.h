/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:49:40 by sihong            #+#    #+#             */
/*   Updated: 2024/02/23 11:49:52 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>

typedef struct timeval	t_timeval;

typedef struct s_philo_info
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				*forks;
	int				*end_checker;
	pthread_mutex_t	*mutex;
	int				start_time;
	int				termination;
}	t_philo_info;

typedef struct s_philo_stat
{
	int				philo_num;
	t_philo_info	*philo_info;
}	t_philo_stat;

//utils.c
int				check_invalid_input(int argc, char **argv);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
//free_struct.c
void			free_philo_info(t_philo_info *philo_info);
void			free_philo_stat(t_philo_stat *philo_stat);
//alloc_philo_stat.c
pthread_mutex_t	*alloc_mutexs(int philo_num);
int				alloc_forks_checker(t_philo_info *philo_info);
t_philo_info	*alloc_philo_info(int argc, char **argv);
t_philo_stat	*alloc_philo_stat(int argc, char **argv);
//philo_utils_2.c
int				get_current_time(void);
int				get_time_from_start(int start_time);
//philo_utils.c
int				sleep_check_death(t_philo_stat *ps, int last_meal_time);
int				check_end_dining(int *end_checker, int len);
int				check_termination(t_philo_stat *ps, int print_msg, char *s);
int				wait_for_cycle(t_philo_stat *ps, int last_meal_time, int cycle);
//philo_actions_2.c
int				delay_start(t_philo_stat *ps, \
				int last_meal_time, int time_to_delay);
//philo_actions.c
int				philo_sleep(t_philo_stat *ps, int last_meal_time);
int				philo_think(t_philo_stat *ps, int last_meal_time);
int				philo_eat_2(int *left_fork, int *right_fork, \
				int *meal_ate, t_philo_stat *ps);
int				philo_eat(t_philo_stat *ps, int *last_meal_time, int *meal_ate);
void			philo_hold_forks(t_philo_stat *ps);
//philosophers_2.c
void			*philo_lonely_case(void *philo_stat);
void			*philo_even_case(void *philo_stat);
void			*philo_odd_sleepyhead_case(void *philo_stat);
void			wait_for_timing(int i, int *turn, \
				t_philo_stat *ps, int last_meal_time);
void			*philo_odd_normal_case(void *philo_stat);
//philosophers.c
void			wait_for_gap(int i, int *turn, \
				t_philo_stat *ps, int last_meal_time);
void			*philo_odd_insomnia_case(void *philo_stat);
void			philo_odd_cases(pthread_t *pt, t_philo_stat *ps);
void			philosophers(pthread_t *pt, t_philo_stat *ps);

#endif
