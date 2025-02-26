/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:43:33 by sihong            #+#    #+#             */
/*   Updated: 2024/01/24 13:43:41 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_cmd_hd(char **envp, t_fds *fds, char ***args)
{
	pid_t	pid;

	pipe_adv(fds->pipe_fd);
	parse_here_doc(fds->pipe_fd, args[0][0]);
	pipe_adv(fds->pipe2_fd);
	fork_adv(&pid);
	if (pid == 0)
	{
		dup2_adv(fds->pipe_fd[READ], 0);
		dup2_adv(fds->pipe2_fd[WRITE], 1);
		close_adv(fds->pipe_fd[READ]);
		close_adv(fds->pipe_fd[WRITE]);
		close_adv(fds->pipe2_fd[READ]);
		close_adv(fds->pipe2_fd[WRITE]);
		execve_adv(args[1], envp);
	}
	close_adv(fds->pipe_fd[READ]);
	close_adv(fds->pipe_fd[WRITE]);
	fds->pipe_fd[READ] = fds->pipe2_fd[READ];
	fds->pipe_fd[WRITE] = fds->pipe2_fd[WRITE];
	fds->pipe2_fd[READ] = -1;
	fds->pipe2_fd[WRITE] = -1;
}

void	parse_here_doc(int fd[2], char *limiter)
{
	char	*s;
	char	*tmp;

	while (1)
	{
		s = get_next_line(0);
		tmp = ft_strtrim(s, "\n");
		if (tmp == 0)
			print_error_exit("error : ft_strtrim failed.\n");
		if (ft_strncmp(limiter, tmp, ft_strlen(limiter) + 1) == 0)
		{
			free(s);
			free(tmp);
			break ;
		}
		if (write(fd[WRITE], s, ft_strlen(s)) == -1)
			print_error_exit("error : write failed.\n");
		free(s);
		free(tmp);
	}
}

void	mid_cmd(char **envp, t_fds *fds, char **args)
{
	pid_t	pid;

	pipe_adv(fds->pipe2_fd);
	fork_adv(&pid);
	if (pid == 0)
	{
		dup2_adv(fds->pipe_fd[READ], 0);
		dup2_adv(fds->pipe2_fd[WRITE], 1);
		close_adv(fds->pipe_fd[READ]);
		close_adv(fds->pipe_fd[WRITE]);
		close_adv(fds->pipe2_fd[READ]);
		close_adv(fds->pipe2_fd[WRITE]);
		execve_adv(args, envp);
	}
	close_adv(fds->pipe_fd[READ]);
	close_adv(fds->pipe_fd[WRITE]);
	fds->pipe_fd[READ] = fds->pipe2_fd[READ];
	fds->pipe_fd[WRITE] = fds->pipe2_fd[WRITE];
	fds->pipe2_fd[READ] = -1;
	fds->pipe2_fd[WRITE] = -1;
}

void	last_cmd(t_ar_en ar_en, int pipe_fd[2], char ***args, int here_doc)
{
	pid_t	pid;
	int		file_fd;

	if (here_doc == 0)
		file_fd = open(args[ar_en.argc - 2][0],
				O_CREAT | O_TRUNC | O_RDWR, 0644);
	else
		file_fd = open(args[ar_en.argc - 3][0],
				O_CREAT | O_APPEND | O_RDWR, 0644);
	if (file_fd == -1)
		print_error_exit("error : open failed.\n");
	fork_adv(&pid);
	if (pid == 0)
	{
		dup2_adv(pipe_fd[READ], 0);
		dup2_adv(file_fd, 1);
		close_adv(file_fd);
		close_adv(pipe_fd[READ]);
		close_adv(pipe_fd[WRITE]);
		execve_adv(args[ar_en.argc - 3 - here_doc], ar_en.envp);
	}
	close_adv(pipe_fd[READ]);
	close_adv(pipe_fd[WRITE]);
	close_adv(file_fd);
}

void	pipex(int argc, char ***args, char **envp, int here_doc)
{
	int		i;
	t_fds	fds;
	t_ar_en	ar_en;

	fds.pipe_fd[0] = 0;
	fds.pipe2_fd[0] = 0;
	if (here_doc == 0)
		first_cmd(envp, fds.pipe_fd, args);
	else
		first_cmd_hd(envp, &fds, args);
	i = 2;
	while (i < argc - 3 - here_doc)
	{
		mid_cmd(envp, &fds, args[i]);
		i++;
	}
	ar_en.argc = argc;
	ar_en.envp = envp;
	last_cmd(ar_en, fds.pipe_fd, args, here_doc);
	wait_child_end(argc - 3 - here_doc);
}
