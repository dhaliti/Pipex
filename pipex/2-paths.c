/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-paths.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:23:36 by dhaliti           #+#    #+#             */
/*   Updated: 2022/03/07 19:58:23 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*system_paths(char **envp)
{
	int	i;

	i = 0;
	while (*envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **envp, char **path)
{
	char	**mypaths;
	char	*path_cmd;
	int		i;
	int		fd;

	i = -1;
	mypaths = ft_split(system_paths(envp), ':');
	while (mypaths[++i])
	{
		path_cmd = ft_strjoin(ft_strjoin(mypaths[i], "/"), cmd);
		fd = open(path_cmd, O_RDONLY);
		if (fd >= 0)
		{
			if (access(path_cmd, F_OK) == -1)
				exit_error("Command not found: ", cmd, 2, 127);
			*path = path_cmd;
			free_all(mypaths);
			close (fd);
			return (*path);
		}
		free (path_cmd);
	}
	free_all(mypaths);
	return (NULL);
}

void	exit_error(char *s, char *argv, int fd, int code)
{
	ft_putstr_fd(s, fd);
	ft_putendl_fd(argv, 2);
	exit(code);
}
