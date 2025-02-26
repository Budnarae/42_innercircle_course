/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:22:01 by sihong            #+#    #+#             */
/*   Updated: 2024/02/23 20:22:16 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	check_invalid_input(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j += 1;
		}
		i += 1;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	char	*result_copy;
	size_t	i;

	result = malloc(size * count);
	if (result == 0)
		exit(1);
	result_copy = (char *)result;
	i = 0;
	while (i < size * count)
		result_copy[i++] = 0;
	return (result);
}

pid_t	fork_adv(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit(1);
	return (pid);
}

sem_t	*sem_open_adv(const char *name, int oflag, \
		mode_t mode, unsigned int value)
{
	sem_t	*semaphore;

	semaphore = sem_open(name, \
		oflag, mode, value);
	if (semaphore == SEM_FAILED)
	{
		printf("sem_open failed\n");
		exit(1);
	}
	return (semaphore);
}
