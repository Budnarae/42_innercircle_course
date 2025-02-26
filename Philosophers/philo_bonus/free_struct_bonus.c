/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:32:51 by sihong            #+#    #+#             */
/*   Updated: 2024/02/23 20:33:01 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	unlink_all_semaphore(t_philo_info *philo_info)
{
	int		i;
	char	*s;

	sem_unlink("/forks");
	i = 0;
	while (i < philo_info->num_of_philo)
	{
		s = ft_itoa(i);
		sem_unlink(s);
		free(s);
		i += 1;
	}
	sem_unlink("/mutex");
}

void	free_philo_info(t_philo_info *philo_info)
{
	unlink_all_semaphore(philo_info);
	free(philo_info->end_checker);
	free(philo_info);
}

void	free_philo_stat(t_philo_stat *philo_stat)
{
	free_philo_info(philo_stat[0].philo_info);
	free(philo_stat);
}
