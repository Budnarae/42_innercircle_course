/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:55:47 by chansjeo          #+#    #+#             */
/*   Updated: 2024/02/05 21:49:24 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr_fd(int n, int fd)
{
	int		mod;
	int		len;
	long	num;

	len = 0;
	num = n;
	if (n < 0)
	{
		if (write(fd, "-", 1) == -1)
			return (-1);
		num = -num;
	}
	if (num >= 10)
	{
		len += ft_putnbr_fd(num / 10, fd);
		if (len <= -1)
			return (-1);
	}
	mod = num % 10 + '0';
	if (write(fd, &mod, 1) == -1)
		return (-1);
	return (len + 1 + (n < 0));
}
/*
void	 ft_putnbr_fd(int n, int *i)
{
	int	mod;
	long num;

	num = n;
	if (n < 0)
	{
		write(1, "-", 1);
		*i += 1;
		num = -num;
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10);
	mod = num % 10 + '0';
	write(1, &mod, 1);
	*i += 1;
}
*/
