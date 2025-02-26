/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:49:40 by sihong            #+#    #+#             */
/*   Updated: 2024/02/23 11:49:52 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <signal.h>

typedef struct timeval	t_timeval;

typedef struct s_philo_info
{
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat;
	sem_t		*forks;
	sem_t		**end_checker;
	sem_t		*mutex;
	pthread_t	pt;
	int			start_time;
	int			termination;
}	t_philo_info;

typedef struct s_philo_stat
{
	int				philo_num;
	t_philo_info	*philo_info;
}	t_philo_stat;

//utils_bonus.c
int				check_invalid_input(int argc, char **argv);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
pid_t			fork_adv(void);
sem_t			*sem_open_adv(const char *name, int oflag, \
				mode_t mode, unsigned int value);
//utils_bonus_2.c
int				waitpid_adv(pid_t pid, int *wstatus, int options);
void			is_sign_negative(long long *n_temp, int *sign, size_t *len);
size_t			find_len(long long n_temp);
char			*ft_itoa(int n);
//free_struct_bonus.c
void			unlink_all_semaphore(t_philo_info *philo_info);
void			free_philo_info(t_philo_info *philo_info);
void			free_philo_stat(t_philo_stat *philo_stat);
//alloc_philo_stat_bonus.c
void			alloc_semaphore(t_philo_info *philo_info);
t_philo_info	*alloc_philo_info(int argc, char **argv);
t_philo_stat	*alloc_philo_stat(int argc, char **argv);
//philo_utils_bonus.c
void			sleep_check_death(t_philo_stat *ps, int last_meal_time);
void			wait_for_cycle(t_philo_stat *ps, int last_meal_time, int cycle);
//philo_utils_bonus_2.c
int				get_current_time(void);
int				get_time_from_start(int start_time);
void			check_end(t_philo_stat *ps);
void			check_termination(t_philo_stat *ps, int print_msg, char *s);
//philo_actions_bonus.c
void			philo_sleep(t_philo_stat *ps, int last_meal_time);
void			philo_think(t_philo_stat *ps, int last_meal_time);
void			philo_eat(t_philo_stat *ps, int *last_meal_time, int *meal_ate);
void			philo_hold_forks(t_philo_stat *ps);
//philo_actions_bonus_2.c
int				delay_start(t_philo_stat *ps, \
				int last_meal_time, int time_to_delay);
//philosophers_bonus.c
void			philo_odd_normal_case(t_philo_stat *ps);
void			*philo_odd_insomnia_case(t_philo_stat *ps);
void			zombie_collecter(pid_t *pid, t_philo_stat *ps);
void			child_part(int i, t_philo_stat *ps);
void			philosophers(pid_t *pid, t_philo_stat *ps);
//philosophers_bonus_2.c
void			*check_end_dining(void *philo_stat);
void			philo_lonely_case(t_philo_stat *ps);
void			philo_even_case(t_philo_stat *ps);
void			philo_odd_sleepyhead_case(t_philo_stat *ps);
void			wait_for_timing(int i, int *turn, \
				t_philo_stat *ps, int last_meal_time);
//philosophers_bonus_3.c
void			syncronize_start_time(t_philo_stat *ps);

#endif
