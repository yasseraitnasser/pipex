/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_processes_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:31:43 by yait-nas          #+#    #+#             */
/*   Updated: 2024/03/10 23:53:13 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_child(int argc, char **av_env[2], int **fd, char *secure_path)
{
	char	**cmd_splited;
	char	*path;

	dup_close1(av_env, fd, argc, secure_path);
	cmd_splited = ft_split(av_env[0][2], ' ');
	if (!cmd_splited)
		free_sec_fd_quit(argc, secure_path, fd);
	path = get_path(secure_path, cmd_splited);
	if (!path)
		free_sec_fd_cmd_quit(argc, secure_path, fd, cmd_splited);
	if (execve(path, cmd_splited, av_env[1]) == -1)
	{
		free_in_case(cmd_splited, path, secure_path);
		ft_error("Command not found!\n");
	}
}

void	mid_child(char **av_env[2], int **fd, int i, char *secure_path)
{
	char	**cmd_splited;
	char	*path;
	int		argc;

	argc = how_many_args(av_env[0]);
	dup_close2(fd, i, argc);
	cmd_splited = ft_split(av_env[0][i + 2], ' ');
	if (!cmd_splited)
		free_sec_fd_quit(argc, secure_path, fd);
	path = get_path(secure_path, cmd_splited);
	if (!path)
		free_sec_fd_cmd_quit(argc, secure_path, fd, cmd_splited);
	if (execve(path, cmd_splited, av_env[1]) == -1)
	{
		free_in_case(cmd_splited, path, secure_path);
		ft_error("Command not found!\n");
	}
}

void	last_child(int argc, char **av_env[2], int **fd, char *secure_path)
{
	char	**cmd_splited;
	char	*path;

	dup_close3(av_env, fd, argc, secure_path);
	cmd_splited = ft_split(av_env[0][argc - 2], ' ');
	if (!cmd_splited)
		free_sec_fd_quit(argc, secure_path, fd);
	path = get_path(secure_path, cmd_splited);
	if (!path)
		free_sec_fd_cmd_quit(argc, secure_path, fd, cmd_splited);
	if (execve(path, cmd_splited, av_env[1]) == -1)
	{
		free_in_case(cmd_splited, path, secure_path);
		ft_error("Command not found!\n");
	}
}

void	run_child_processses(int argc, char **av_env[2], int **fd, char *sec)
{
	int	i;
	int	pid;

	i = 0;
	while (i < argc - 3)
	{
		pid = fork();
		if (pid == -1)
			ft_perror(NULL);
		if (!pid)
		{
			if (i == 0)
				first_child(argc, av_env, fd, sec);
			else if (i == argc - 4)
				last_child(argc, av_env, fd, sec);
			else
				mid_child(av_env, fd, i, sec);
		}
		i++;
	}
}

void	child_processes_bonus(int argc, char **argv, char **env, char *sec)
{
	int		**fd;
	int		i;
	char	**av_env[2];

	i = 0;
	fd = prepare_pipe(argc);
	while (i < argc - 4)
	{
		if (pipe(fd[i++]) == -1)
			ft_perror(NULL);
	}
	av_env[0] = argv;
	av_env[1] = env;
	run_child_processses(argc, av_env, fd, sec);
	close_them_all(fd, argc);
	free_fd(fd, argc);
	i = -1;
	while (++i < argc - 3)
		wait(NULL);
}
