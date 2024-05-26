/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_processes_helper_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 23:44:15 by yait-nas          #+#    #+#             */
/*   Updated: 2024/03/10 23:45:50 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_sec_fd_quit(int argc, char *sec, int **fd)
{
	free(sec);
	free_fd(fd, argc);
	ft_error("Command not found!\n");
}

void	free_sec_fd_cmd_quit(int argc, char *sec, int **fd, char **cmd)
{
	free_one(cmd);
	free_sec_fd_quit(argc, sec, fd);
}

void	dup_close1(char **av_env[2], int **fd, int argc, char *sec)
{
	int	fd_infile;

	close_unneeded1(fd, argc, 0);
	close(fd[0][0]);
	fd_infile = open(av_env[0][1], O_RDONLY);
	if (dup2(fd[0][1], STDOUT_FILENO) == -1)
		ft_perror(NULL);
	close(fd[0][1]);
	if (dup2(fd_infile, STDIN_FILENO) == -1)
	{
		free_fd(fd, argc);
		free(sec);
		ft_error("No such file or directory\n");
	}
	close(fd_infile);
}

void	dup_close2(int **fd, int i, int argc)
{
	close_unneeded2(fd, argc, i);
	close(fd[i - 1][1]);
	close(fd[i][0]);
	if (dup2(fd[i][1], STDOUT_FILENO) == -1)
		ft_perror(NULL);
	close(fd[i][1]);
	if (dup2(fd[i - 1][0], STDIN_FILENO) == -1)
		ft_perror(NULL);
	close(fd[i - 1][0]);
}

void	dup_close3(char **av_env[2], int **fd, int argc, char *secure_path)
{
	int	fd_outfile;

	close_unneeded1(fd, argc, argc - 5);
	close(fd[argc - 5][1]);
	fd_outfile = open(av_env[0][argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_outfile == -1)
	{
		free_fd(fd, argc);
		free(secure_path);
		ft_perror(NULL);
	}
	if (dup2(fd_outfile, STDOUT_FILENO) == -1)
		ft_perror(NULL);
	close(fd_outfile);
	if (dup2(fd[argc - 5][0], STDIN_FILENO) == -1)
		ft_perror(NULL);
	close(fd[argc - 5][0]);
}
