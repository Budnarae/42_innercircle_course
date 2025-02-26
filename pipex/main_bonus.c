/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:14:28 by sihong            #+#    #+#             */
/*   Updated: 2024/01/23 19:14:38 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	char	***args;
	int		here_doc;

	if (ft_strncmp("here_doc", argv[1], 9) != 0)
		here_doc = 0;
	else
		here_doc = 1;
	if (argc < 5 + here_doc)
		print_error_exit("error : wrong input format.\n");
	args = parse_args(argc, argv, envp, here_doc);
	pipex(argc, args, envp, here_doc);
	free_args(argc, args, here_doc);
	return (0);
}
