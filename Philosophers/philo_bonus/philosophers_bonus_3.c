/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:54:51 by sihong            #+#    #+#             */
/*   Updated: 2024/03/07 10:55:04 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	syncronize_start_time(t_philo_stat *ps)
{
	while (get_current_time() - ps->philo_info->start_time < 1000000)
		usleep(100);
	ps->philo_info->start_time = get_current_time();
}
