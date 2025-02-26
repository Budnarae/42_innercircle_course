/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:52:33 by sihong            #+#    #+#             */
/*   Updated: 2024/02/28 14:52:44 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_current_time(void)
{
	t_timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((int)(current_time.tv_sec * 1000000) + current_time.tv_usec);
}

int	get_time_from_start(int start_time)
{
	return ((get_current_time() - start_time) / 1000);
}
