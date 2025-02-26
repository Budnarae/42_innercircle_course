/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:49:03 by sihong            #+#    #+#             */
/*   Updated: 2024/01/24 13:49:11 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*paste_path_cmd(char *path, char *args)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(path, "/");
	if (tmp == 0)
		print_error_exit("error : ft_strjoin failed.\n");
	tmp2 = ft_strjoin(tmp, args);
	if (tmp2 == 0)
		print_error_exit("error : ft_strjoin failed.\n");
	free(tmp);
	return (tmp2);
}
