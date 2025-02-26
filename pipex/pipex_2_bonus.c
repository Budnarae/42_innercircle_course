/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:19:10 by sihong            #+#    #+#             */
/*   Updated: 2024/01/24 17:19:20 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_cmd(char **envp, int pipe_fd[2], char ***args)
{
	pid_t	pid;
	int		file_fd;

	file_fd = open(args[0][0], O_RDONLY);
	if (file_fd == -1)
		print_error_exit("error : open failed.\n");
	pipe_adv(pipe_fd);
	fork_adv(&pid);
	if (pid == 0)
	{
		dup2_adv(file_fd, 0);
		dup2_adv(pipe_fd[WRITE], 1);
		close_adv(file_fd);
		close_adv(pipe_fd[READ]);
		close_adv(pipe_fd[WRITE]);
		execve_adv(args[1], envp);
	}
	close_adv(file_fd);
}
