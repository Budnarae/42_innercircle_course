/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:14:28 by sihong            #+#    #+#             */
/*   Updated: 2024/01/23 19:14:38 by sihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	***args;

	if (argc != 5)
		print_error_exit("error : there must be 4 inputs.\n");
	args = parse_args(argc, argv, envp);
	pipex(argc, args, envp);
	free_args(argc, args);
	return (0);
}
