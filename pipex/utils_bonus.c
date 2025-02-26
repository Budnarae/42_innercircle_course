/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:18:11 by sihong            #+#    #+#             */
/*   Updated: 2024/01/23 19:18:24 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	print_error_exit(const char *s)
{
	perror(s);
	exit(1);
}

void	free_args(int argc, char ***args, int here_doc)
{
	int	i;
	int	j;

	free(args[0]);
	i = 1;
	while (i < argc - 2 - here_doc)
	{
		j = 0;
		while (args[i][j])
		{
			free(args[i][j]);
			j++;
		}
		free(args[i]);
		i++;
	}
	free(args[argc - 2 - here_doc]);
	free(args);
}

void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

void	fork_adv(pid_t *pid)
{
	*pid = fork();
	if (*pid == -1)
		print_error_exit("error : fork error.\n");
}

void	pipe_adv(int fd[2])
{
	if (pipe(fd) == -1)
		print_error_exit("error : pipe failed.\n");
}
