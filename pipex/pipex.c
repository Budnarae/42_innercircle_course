/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:43:33 by sihong            #+#    #+#             */
/*   Updated: 2024/01/24 13:43:41 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	last_cmd(int argc, char **envp, int pipe_fd[2], char ***args)
{
	pid_t	pid;
	int		file_fd;

	file_fd = open(args[argc - 2][0], O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (file_fd == -1)
		print_error_exit("error : open failed.\n");
	fork_adv(&pid);
	if (pid == 0)
	{
		dup2_adv(pipe_fd[READ], 0);
		dup2_adv(file_fd, 1);
		close_adv(pipe_fd[READ]);
		close_adv(pipe_fd[WRITE]);
		close_adv(file_fd);
		execve_adv(args[argc - 3], envp);
	}
	close_adv(pipe_fd[READ]);
	close_adv(pipe_fd[WRITE]);
	close_adv(file_fd);
}

void	pipex(int argc, char ***args, char **envp)
{
	int	pipe_fd[2];

	first_cmd(envp, pipe_fd, args);
	last_cmd(argc, envp, pipe_fd, args);
	wait_child_end(2);
}
