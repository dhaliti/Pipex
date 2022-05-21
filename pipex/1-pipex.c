/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-pipex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:56:58 by dhaliti           #+#    #+#             */
/*   Updated: 2022/03/08 11:42:54 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	first_process(int *end, char **argv, char **envp)
{
	int		fd;
	char	**cmd;
	char	*path;

	close(end[0]);
	dup2(end[1], STDOUT_FILENO);
	close(end[1]);
	fd = open(argv[1], O_RDONLY);
	file_checker(argv[1], fd);
	dup2(fd, STDIN_FILENO);
	cmd = ft_split(argv[2], ' ');
	find_path(cmd[0], envp, &path);
	if (execve(path, cmd, envp) == -1)
	{
		free_all(cmd);
		free(path);
		exit (0);
	}
}

static void	second_process(int *end, char **argv, char **envp)
{
	int		fd;
	char	**cmd;
	char	*path;

	close(end[1]);
	dup2(end[0], STDIN_FILENO);
	close(end[0]);
	fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0664);
	file_checker(argv[4], fd);
	dup2(fd, STDOUT_FILENO);
	cmd = ft_split(argv[3], ' ');
	path = find_path(cmd[0], envp, &path);
	if (execve(path, cmd, envp) == -1)
	{
		free_all(cmd);
		free(path);
		exit (0);
	}
}

static void	pipex(char **argv, char **envp)
{
	int		end[2];
	pid_t	child;

	pipe(end);
	child = fork();
	if (child < 0)
		perror("Fork: ");
	if (child == 0)
		first_process(end, argv, envp);
	else
	{
		child = fork();
		if (child < 0)
			perror("Fork: ");
		if (child == 0)
			second_process(end, argv, envp);
		else
		{
			close(end[0]);
			close(end[1]);
		}
	}
	waitpid(child, NULL, 0);
}

static int	check_args(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("Incorrect number of arguments\n", 2);
		ft_putstr_fd("Format: ./pipex file1 'cmd1' 'cmd2' file2\n", 2);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	check_args(argc);
	pipex (argv, envp);
	return (0);
}
