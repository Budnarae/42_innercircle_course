/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:59:53 by chansjeo          #+#    #+#             */
/*   Updated: 2024/06/29 18:24:31 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

void	ft_error_msg(char *str, int exit_status)
{
	ft_putstr_fd(str, 2);
	exit(exit_status);
}

void	*ft_calloc_adv(size_t count, size_t size)
{
	void	*alloc;

	if (!count)
		return (0);
	alloc = ft_calloc(count, size);
	if (!alloc)
		ft_error_msg("malloc failed!\n", 255);
	return (alloc);
}

char	**ft_split_adv(char *str)
{
	char	**res;

	res = ft_split(str, ' ');
	if (!res)
		ft_error_msg("ft_split failed!\n", 255);
	return (res);
}

int	open_read_only(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error_msg("open failed\n", 1);
	return (fd);
}
