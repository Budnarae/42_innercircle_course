/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:29:43 by sihong            #+#    #+#             */
/*   Updated: 2024/01/17 16:29:47 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define READ 0
# define WRITE 1

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include "libft/libft.h"

// utils.c
void	print_error_exit(const char *s);
void	free_args(int argc, char ***args);
void	free_path(char **path);
void	fork_adv(pid_t *pid);
void	pipe_adv(int fd[2]);
// utils_2.c
void	dup2_adv(int fd1, int fd2);
void	close_adv(int fd);
void	execve_adv(char **args, char **envp);
void	wait_child_end(int child_num);
// parse_args.c
int		get_path_index(char **envp);
char	**get_path(char **envp);
char	***get_args(int argc, char **argv);
void	get_cmd(int argc, char **path, char ***args);
char	***parse_args(int argc, char **argv, char **envp);
// parse_args_2.c
char	*paste_path_cmd(char *path, char *args);
// pipex.c
void	first_cmd(char **envp, int pipe_fd[2], char ***args);
void	last_cmd(int argc, char **envp, int pipe_fd[2], char ***args);
void	pipex(int argc, char ***args, char **envp);

#endif