/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_processes_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 23:55:42 by yait-nas          #+#    #+#             */
/*   Updated: 2024/03/11 00:00:37 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_sec_quit(char *secure_path, char *str)
{
	free(secure_path);
	ft_error(str);
}

void	free_sec_cmd_quit(char *secure_path, char *str, char **cmd)
{
	free_one(cmd);
	free_sec_quit(secure_path, str);
}

void	dup_close1(int fd[4], char *secure_path)
{
	if (dup2(fd[2], STDIN_FILENO) == -1)
		free_sec_quit(secure_path, "No such file or directory\n");
	close(fd[2]);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_perror(NULL);
	close(fd[1]);
	close(fd[0]);
}

void	dup_close2(int fd[4])
{
	if (dup2(fd[3], STDOUT_FILENO) == -1)
		ft_perror(NULL);
	close(fd[3]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_perror(NULL);
	close(fd[0]);
	close(fd[1]);
}
