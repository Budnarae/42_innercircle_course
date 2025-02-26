/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:36:01 by sihong            #+#    #+#             */
/*   Updated: 2024/02/29 14:36:10 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	delay_start(t_philo_stat *ps, int last_meal_time, int time_to_delay)
{
	if (check_termination(ps, 1, "is thinking") == 0)
		return (0);
	if (wait_for_cycle(ps, last_meal_time, time_to_delay) == 0)
		return (0);
	return (1);
}
