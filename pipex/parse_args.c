/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:19:57 by sihong            #+#    #+#             */
/*   Updated: 2024/01/23 19:20:08 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_path_index(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	return (i);
}

char	**get_path(char **envp)
{
	int		path_idx;
	char	*tmp;
	char	**path;

	path_idx = get_path_index(envp);
	if (envp[path_idx] == 0)
		return (0);
	tmp = ft_substr(envp[path_idx], 5, ft_strlen(envp[path_idx]));
	if (tmp == 0)
		print_error_exit("error : ft_substr failed.\n");
	path = ft_split(tmp, ':');
	if (path == 0)
		print_error_exit("error : ft_split failed.\n");
	free(tmp);
	return (path);
}

char	***get_args(int argc, char **argv)
{
	int		i;
	char	***args;

	args = ft_calloc(argc, sizeof(char **));
	if (args == 0)
		print_error_exit("error : ft_calloc failed.\n");
	args[0] = ft_calloc(2, sizeof(char *));
	if (args[0] == 0)
		print_error_exit("error : ft_calloc failed.\n");
	args[argc - 2] = ft_calloc(2, sizeof(char *));
	if (args[argc - 2] == 0)
		print_error_exit("error : ft_calloc failed.\n");
	args[0][0] = argv[1];
	args[argc - 2][0] = argv[argc - 1];
	i = 1;
	while (i < argc - 2)
	{
		args[i] = ft_split(argv[i + 1], ' ');
		if (args[i] == 0)
			print_error_exit("error : ft_split failed.\n");
		i++;
	}
	return (args);
}

void	get_cmd(int argc, char **path, char ***args)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < argc - 2)
	{
		j = -1;
		while (path[++j])
		{
			if (args[i][0] == 0)
				continue ;
			tmp = paste_path_cmd(path[j], args[i][0]);
			if (access(tmp, F_OK) == 0)
			{
				free(args[i][0]);
				args[i][0] = tmp;
			}
			else
				free(tmp);
		}
		i++;
	}
}

char	***parse_args(int argc, char **argv, char **envp)
{
	char	***args;
	char	**path;

	args = get_args(argc, argv);
	path = get_path(envp);
	if (path == 0)
		return (args);
	get_cmd(argc, path, args);
	free_path(path);
	return (args);
}
