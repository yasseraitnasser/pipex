/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_helper_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 00:41:20 by yait-nas          #+#    #+#             */
/*   Updated: 2024/03/11 00:43:04 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_sec_quit(char *secure_path)
{
	free(secure_path);
	ft_error("Command not found!\n");
}

void	free_sec_cmd_quit(char *secure_path, char **cmd)
{
	free_one(cmd);
	free_sec_quit(secure_path);
}

void	dup_close5(char **argv, int fd[4], char *secure_path)
{
	int	fd_out;

	fd_out = open(argv[5], O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd_out == -1)
	{
		free(secure_path);
		ft_perror(NULL);
	}
	close(fd[3]);
	if (dup2(fd[2], STDIN_FILENO) == -1)
		ft_perror(NULL);
	close(fd[2]);
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		ft_perror(NULL);
	close(fd_out);
}

void	dup_close4(int fd[4])
{
	close(fd[2]);
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_perror(NULL);
	close(fd[0]);
	if (dup2(fd[3], STDOUT_FILENO) == -1)
		ft_perror(NULL);
	close(fd[3]);
}

void	keep_going(char *tmp1, char *limiter, int fd[2])
{
	char	*str;
	char	*tmp2;

	str = NULL;
	while (ft_strcmp(limiter, tmp1))
	{
		tmp2 = str;
		str = ft_strjoin(str, tmp1);
		free(tmp2);
		free(tmp1);
		tmp1 = get_next_line(0);
		if (!tmp1)
			break ;
	}
	free(limiter);
	free(tmp1);
	if (str)
		write(fd[1], str, ft_strlen(str));
	else
		write(fd[1], "", 0);
	free(str);
}
