/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:57:34 by yait-nas          #+#    #+#             */
/*   Updated: 2024/03/11 00:46:11 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execution(char *path, char **cmd_splited, char **env, char *sec)
{
	if (execve(path, cmd_splited, env) == -1)
	{
		free_in_case(cmd_splited, path, sec);
		ft_error("Command not found!\n");
	}
}

void	child_p2(char **argv, int fd[4], char *secure_path, char **env)
{
	int		pid;
	char	**cmd_splited;
	char	*path;

	pid = fork();
	if (pid == -1)
		ft_perror(NULL);
	if (!pid)
	{
		dup_close5(argv, fd, secure_path);
		cmd_splited = ft_split(argv[4], ' ');
		if (!cmd_splited)
			free_sec_quit(secure_path);
		path = get_path(secure_path, cmd_splited);
		if (!path)
			free_sec_cmd_quit(secure_path, cmd_splited);
		execution(path, cmd_splited, env, secure_path);
	}
}

void	child_p1(char **argv, int fd[4], char *secure_path, char **env)
{
	int		pid;
	char	**cmd_splited;
	char	*path;

	pid = fork();
	if (pid == -1)
		ft_perror(NULL);
	if (!pid)
	{
		dup_close4(fd);
		cmd_splited = ft_split(argv[3], ' ');
		if (!cmd_splited)
			free_sec_quit(secure_path);
		path = get_path(secure_path, cmd_splited);
		if (!path)
			free_sec_cmd_quit(secure_path, cmd_splited);
		if (execve(path, cmd_splited, env) == -1)
		{
			free_in_case(cmd_splited, path, secure_path);
			ft_error("Command not found!\n");
		}
	}
}

void	child_process_here_doc(char **argv, int fd[2], char **env, char *sec)
{
	int		fd_cmd[2];
	int		fd_total[4];

	if (pipe(fd_cmd) == -1)
		ft_perror(NULL);
	fd_total[0] = fd[0];
	fd_total[1] = fd[1];
	fd_total[2] = fd_cmd[0];
	fd_total[3] = fd_cmd[1];
	child_p1(argv, fd_total, sec, env);
	close(fd_total[0]);
	close(fd_total[1]);
	child_p2(argv, fd_total, sec, env);
	close(fd_total[2]);
	close(fd_total[3]);
	wait(NULL);
	wait(NULL);
	free(sec);
	exit(EXIT_SUCCESS);
}

void	here_doc(char **argv, char **env, char *secure_path)
{
	int		fd[2];
	char	*tmp1;
	char	*limiter;

	if (pipe(fd) == -1)
		ft_perror(NULL);
	limiter = ft_strjoin(argv[2], "\n");
	tmp1 = get_next_line(0);
	if (!tmp1)
	{
		free(limiter);
		free(secure_path);
		ft_error("warning: here-document at line 1 delimited by end-of-file");
	}
	keep_going(tmp1, limiter, fd);
	child_process_here_doc(argv, fd, env, secure_path);
}
