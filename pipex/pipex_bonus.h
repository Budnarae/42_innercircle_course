/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:29:43 by sihong            #+#    #+#             */
/*   Updated: 2024/01/17 16:29:47 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# define READ 0
# define WRITE 1

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct s_fds
{
	int	pipe_fd[2];
	int	pipe2_fd[2];
}	t_fds;

typedef struct s_ar_en
{
	int		argc;
	char	**envp;
}	t_ar_en;

// utils_bonus.c
void	print_error_exit(const char *s);
void	free_args(int argc, char ***args, int here_doc);
void	free_path(char **path);
void	fork_adv(pid_t *pid);
void	pipe_adv(int fd[2]);
// utils_2_bonus.c
void	dup2_adv(int fd1, int fd2);
void	close_adv(int fd);
void	execve_adv(char **args, char **envp);
void	wait_child_end(int child_num);
// parse_args_bonus.c
int		get_path_index(char **envp);
char	**get_path(char **envp);
char	***get_args(int argc, char **argv, int here_doc);
void	get_cmd(int argc, char **path, char ***args);
char	***parse_args(int argc, char **argv, char **envp, int here_doc);
// parse_args_2_bonus.c
char	*paste_path_cmd(char *path, char *args);
// pipex_bonus.c
void	first_cmd_hd(char **envp, t_fds *fds, char ***args);
void	parse_here_doc(int fd[2], char *limiter);
void	mid_cmd(char **envp, t_fds *fds, char **args);
void	last_cmd(t_ar_en ar_en, int pipe_fd[2], char ***args, int here_doc);
void	pipex(int argc, char ***args, char **envp, int here_doc);
// pipex_2_bonus.c
void	first_cmd(char **envp, int pipe_fd[2], char ***args);

#endif
