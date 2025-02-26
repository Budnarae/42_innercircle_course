/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:58:23 by sihong            #+#    #+#             */
/*   Updated: 2024/01/24 13:58:32 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	dup2_adv(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		print_error_exit("error : dup2 failed.\n");
}

void	close_adv(int fd)
{
	if (close(fd) == -1)
		print_error_exit("error : close failed.\n");
}

void	execve_adv(char **args, char **envp)
{
	if (execve(args[0], args, envp) == -1)
		print_error_exit("error : execve failed.\n");
}

void	wait_child_end(int child_num)
{
	int	i;
	int	status;

	i = 0;
	while (i < child_num)
	{
		if (wait(&status) == -1)
			print_error_exit("error : wait failed\n");
		i++;
	}
}
