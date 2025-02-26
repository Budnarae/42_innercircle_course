/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:52:09 by chansjeo          #+#    #+#             */
/*   Updated: 2024/06/29 17:52:47 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

static double	cal_atof(char *str, int neg, int digit, int dot)
{
	double	decimal;
	double	ret;

	ret = 0;
	decimal = 0.1;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			digit = *str - '0';
			if (dot)
			{
				ret += digit * decimal;
				decimal /= 10;
			}
			else
				ret = (ret * 10) + digit;
		}
		else if (*str == '.')
			dot = 1;
		else
			break ;
		++str;
	}
	return (ret * neg);
}

static void	valid_check(char *str)
{
	int	cnt;

	cnt = 0;
	if (*str && ft_strlen(str) > 15)
		ft_error_msg("too long value\n", 1);
	if (*str == '.')
		ft_error_msg("invalid value\n", 1);
	while (*str)
	{
		if (!ft_isdigit(*str) && !is_space(str))
		{
			if (*str == '.' && cnt == 0)
				cnt++;
			else
				ft_error_msg("invalid value\n", 1);
		}
		str++;
	}
	if (*--str == '.')
		ft_error_msg("invalid value\n", 1);
}

double	ft_atof(char *str)
{
	int		neg;
	int		digit;
	int		dot;

	neg = 1;
	dot = 0;
	digit = 0;
	while (is_space(str))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	valid_check(str);
	return (cal_atof(str, neg, digit, dot));
}
