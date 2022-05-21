/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:37:19 by dhaliti           #+#    #+#             */
/*   Updated: 2022/03/07 19:42:56 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_args(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("Incorrect number of arguments\n", 2);
		ft_putstr_fd("./pipex file1 cmd1 cmd2 file2\n", 2);
		exit(0);
	}
	return (0);
}

void	free_all(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	file_checker(char *argv, int fd)
{
	if (fd < 0)
	{
		ft_putstr_fd("No such file or access denied: ", 2);
		ft_putendl_fd(argv, 2);
		exit (0);
	}
}
