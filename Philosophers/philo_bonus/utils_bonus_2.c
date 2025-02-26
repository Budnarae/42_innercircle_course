/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:21:20 by sihong            #+#    #+#             */
/*   Updated: 2024/03/01 12:21:35 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	waitpid_adv(pid_t pid, int *wstatus, int options)
{
	int	func_returned;

	func_returned = waitpid(pid, wstatus, options);
	if (func_returned == -1)
		exit(1);
	return (func_returned);
}

void	is_sign_negative(long long *n_temp, int *sign, size_t *len)
{
	if (*n_temp < 0)
	{
		*n_temp *= -1;
		*sign = -1;
		*len += 1;
	}
}

size_t	find_len(long long n_temp)
{
	size_t	len;

	if (n_temp == 0)
		return (1);
	len = 0;
	while (n_temp)
	{
		n_temp /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			sign;
	long long	n_temp;
	size_t		len;
	char		*result;

	n_temp = (long long)n;
	len = find_len(n_temp);
	n_temp = (long long)n;
	is_sign_negative(&n_temp, &sign, &len);
	result = ft_calloc(len + 1, sizeof(char));
	if (sign == -1)
		result[0] = '-';
	if (n_temp == 0)
		result[0] = '0';
	while (n_temp)
	{
		--len;
		result[len] = n_temp % 10 + '0';
		n_temp /= 10;
	}
	return (result);
}
