/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:13:03 by yait-nas          #+#    #+#             */
/*   Updated: 2024/03/11 00:02:20 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process1(int fd[4], char *secure_path, char **argv, char **env)
{
	int		pid;
	char	**cmd1_splited;
	char	*path1;

	pid = fork();
	if (pid == -1)
		ft_perror(NULL);
	if (!pid)
	{
		dup_close1(fd, secure_path);
		cmd1_splited = ft_split(argv[2], ' ');
		if (!cmd1_splited)
			free_sec_quit(secure_path, "Command not found!\n");
		path1 = get_path(secure_path, cmd1_splited);
		if (!path1)
			free_sec_cmd_quit(secure_path,
				"Command not found!\n", cmd1_splited);
		if (execve(path1, cmd1_splited, env) == -1)
		{
			free_in_case(cmd1_splited, path1, secure_path);
			ft_error("Command not found!\n");
		}
	}
}

void	child_process2(int fd[4], char *secure_path, char **argv, char **env)
{
	int		pid;
	char	**cmd2_splited;
	char	*path2;

	pid = fork();
	if (pid == -1)
		ft_perror(NULL);
	if (!pid)
	{
		dup_close2(fd);
		cmd2_splited = ft_split(argv[3], ' ');
		if (!cmd2_splited)
			free_sec_quit(secure_path, "Command not found!\n");
		path2 = get_path(secure_path, cmd2_splited);
		if (!path2)
			free_sec_cmd_quit(secure_path,
				"Command not found!\n", cmd2_splited);
		if (execve(path2, cmd2_splited, env) == -1)
		{
			free_in_case(cmd2_splited, path2, secure_path);
			ft_error("Command not found!\n");
		}
	}
}

void	child_processes(char **argv, char **env, char *secure_path)
{
	int	fd[4];

	fd[2] = open(argv[1], O_RDONLY);
	fd[3] = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd[3] == -1)
	{
		free(secure_path);
		ft_perror(NULL);
	}
	if (pipe(fd) == -1)
		ft_perror(NULL);
	child_process1(fd, secure_path, argv, env);
	child_process2(fd, secure_path, argv, env);
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
	wait(NULL);
	wait(NULL);
}
