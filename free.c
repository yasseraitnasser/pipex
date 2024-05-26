/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:13:08 by yait-nas          #+#    #+#             */
/*   Updated: 2024/03/07 15:46:39 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_one(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	free_two(char **ptr1, char **ptr2)
{
	free_one(ptr1);
	free_one(ptr2);
}

void	free_three(char *ptr1, char **ptr2)
{
	free_one(ptr2);
	free(ptr1);
}

void	free_in_case(char **cmd1_splited, char *path, char *secure_path)
{
	free_one(cmd1_splited);
	free(path);
	free(secure_path);
}
