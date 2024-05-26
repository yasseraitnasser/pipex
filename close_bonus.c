/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:36:19 by yait-nas          #+#    #+#             */
/*   Updated: 2024/03/08 23:53:37 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_them_all(int **fd, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 4)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}

void	close_unneeded1(int **fd, int argc, int needed)
{
	int	i;

	i = 0;
	while (i < argc - 4)
	{
		if (i != needed)
		{
			close(fd[i][0]);
			close(fd[i][1]);
		}
		i++;
	}
}

void	close_unneeded2(int **fd, int argc, int needed)
{
	int	i;

	i = 0;
	while (i < argc - 4)
	{
		if (i != needed && i != needed - 1)
		{
			close(fd[i][0]);
			close(fd[i][1]);
		}
		i++;
	}
}
