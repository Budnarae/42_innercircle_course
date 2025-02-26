/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:32:51 by sihong            #+#    #+#             */
/*   Updated: 2024/02/23 20:33:01 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_philo_info(t_philo_info *philo_info)
{
	int	i;

	if (philo_info->forks)
		free(philo_info->forks);
	if (philo_info->end_checker)
		free(philo_info->end_checker);
	if (philo_info->mutex)
	{
		i = 0;
		while (i <= philo_info->num_of_philo)
			i += 1;
		free(philo_info->mutex);
	}
	free(philo_info);
}

void	free_philo_stat(t_philo_stat *philo_stat)
{
	free_philo_info(philo_stat[0].philo_info);
	free(philo_stat);
}
