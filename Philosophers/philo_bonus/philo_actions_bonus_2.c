/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_bonus_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:36:01 by sihong            #+#    #+#             */
/*   Updated: 2024/02/29 14:36:10 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	delay_start(t_philo_stat *ps, int last_meal_time, int time_to_delay)
{
	check_termination(ps, 1, "is thinking");
	wait_for_cycle(ps, last_meal_time, time_to_delay);
	return (1);
}
